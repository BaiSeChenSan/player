<template>
  <div class="car-detail">
    <h1>汽车详情</h1>

    <div class="car-info-container">
      <!-- 上方区域：车辆信息和图片 -->
      <div class="upper-section">
        <div class="car-info-left">
          <h2>车辆信息</h2>
          <p><strong>品牌:</strong> {{ car.CBrand }}</p>
          <p><strong>型号:</strong> {{ car.CModel }}</p>
          <p><strong>车牌号:</strong> {{ car.CNo }}</p>
          <p><strong>类型:</strong> {{ car.CType }}</p>
          <p>
            <strong>状态:</strong>
            {{ getStatusText(car.CStatus) }}
            <span :class="['status-indicator', getStatusClass(car.CStatus)]"></span>
          </p>
          <p>
            <strong>维修日期:</strong>
            {{ car.CFixDate }}
            <span :class="['status-indicator', isMaintenanceDue(car.CFixDate) ? 'red' : 'green']"></span>
          </p>
          <p>
            <strong>租车单价:</strong>
            <span v-if="!isEditingPrice">¥{{ car.CUnit }}</span>
            <input
              v-else
              type="number"
              v-model.number="car.CUnit"
              @blur="updatePrice"
              class="price-input"
            />
            /天
            <img
              v-if="!isEditingPrice"
              src="..\src\assets\修改.png"
              alt="编辑"
              class="edit-icon"
              @click="editPrice"
            />
          </p>
          <div class="action-buttons">
            <button @click="goToRentDetail" class="action-button rent">租用</button>
            <button @click="goToReturnDetail" class="action-button return">归还</button>
            <button @click="FixDetail" class="action-button fix">维修</button>
            <button @click="DeleteCar" class="action-button delete">删除</button>
          </div>
        </div>

        <div class="car-image-container">
          <img
            :src="getCarImage(car.CNo)"
            alt="汽车图片"
            class="detail-image"
            @error="handleImageError"
          />
        </div>
      </div>

      <!-- 下方区域：出租历史 -->
      <div class="rental-history-section">
        <div class="info-box">
          <h2>出租历史</h2>
          <p v-if="rentalHistory.length === 0">暂无出租记录</p>
          <table v-else class="rental-table">
            <thead>
              <tr>
                <th>出租时间</th>
                <th>归还时间</th>
                <th>租借人手机号</th>
                <th>司机身份证号</th>
                <th>行驶距离</th>
                <th>用车地点</th>
                <th>租车天数</th>
                <th>实付金额</th>
              </tr>
            </thead>
            <tbody>
              <tr v-for="record in rentalHistory" :key="record.invoiceNum">
                <td>{{ record.startTime }}</td>
                <td>{{ record.returnDate || '未归还' }}</td>
                <td>{{ record.guestphone }}</td>
                <td>{{ record.driverId }}</td>
                <td>{{ record.tdistance }} km</td>
                <td>{{ record.locations }}</td>
                <td>{{ record.rentdays }}</td>
                <td>¥{{ record.tmoney }}</td>
              </tr>
            </tbody>
          </table>
        </div>
      </div>
    </div>
  </div>
</template>

<script>
import axios from "axios";

export default {
  props: ["id"], // 接收路由参数
  data() {
    return {
      car: null,
      rentalHistory: [], // 保存所有租车记录
      isEditingPrice: false, // 控制租车单价是否可编辑
      imageError: false, // 标记图片加载错误
    };
  },
  mounted() {
    this.fetchCarDetails();
    this.fetchRentalHistory();
  },
  methods: {
    async fetchCarDetails() {
      try {
        const response = await axios.get(
          `http://localhost:8081/car/${this.id}`
        );
        this.car = response.data;
      } catch (error) {
        console.error("获取车辆详情失败", error);
      }
    },
    async fetchRentalHistory() {
      try {
        const response = await axios.get(
          `http://localhost:8081/car/${this.id}`
        );
        const carnum = response.data.CNo;

        const rentResponse = await axios.get(
          `http://localhost:8081/rent/${carnum}`
        );
        this.rentalHistory = rentResponse.data;
      } catch (error) {
        console.error("获取出租记录失败", error);
      }
    },
    getCarImage() {
      return this.imageError
        ? "https://via.placeholder.com/450x300?text=Image+Not+Available"
        : `https://images.wallpaperscraft.com/image/single/bmw_csl_hommage_105056_800x600.jpg`;
    },
    handleImageError() {
      this.imageError = true;
    },
    isMaintenanceDue(fixDate) {
      const sixMonthsAgo = new Date();
      sixMonthsAgo.setMonth(sixMonthsAgo.getMonth() - 6);
      const maintenanceDate = new Date(fixDate);
      return maintenanceDate < sixMonthsAgo;
    },
    editPrice() {
      this.isEditingPrice = true;
    },
    async updatePrice() {
      this.isEditingPrice = false;
      try {
        const response = await axios.post(
          "http://localhost:8081/car/UpdateUnit",
          {
            id: this.car.id,
            price: this.car.CUnit,
          }
        );
        alert(response.data);
      } catch (error) {
        console.error("更新租车单价失败", error);
        alert("租车单价更新失败");
      }
    },
    goToRentDetail() {
      if (this.car.CStatus == 1) {
        alert("只能在车未出租时才能出租!");
        return;
      }
      this.$router.push({ name: "RentDetail", params: { carId: this.car.id } });
    },
    goToReturnDetail() {
      if (this.car.CStatus == 0) {
        alert("只能在车已出租时才能还车!");
        return;
      }
      this.$router.push({
        name: "ReturnDetail",
        params: { carId: this.car.id },
      });
    },
    async DeleteCar() {
      await axios.get(
        `http://localhost:8081/car/d/${this.id}`
      );
      this.$router.push({ name: "VehicleManagement" });
      alert("删除成功");
    },
    getCurrentTime() {
      const now = new Date();
      const yyyy = now.getFullYear();
      const mm = (now.getMonth() + 1).toString().padStart(2, "0");
      const dd = now.getDate().toString().padStart(2, "0");
      return `${yyyy}-${mm}-${dd}`;
    },
    async FixDetail() {
      if (!this.car) {
        alert("车辆信息加载失败");
        return;
      }

      const currentStatus = this.car.CStatus;

      if (currentStatus === "0") {
        axios
          .post("http://localhost:8081/car/UpdateStatus2", {
            id: this.car.id,
          })
          .then(() => {
            alert("车辆状态已更新为维修中");
            this.car.CStatus = "2";
          })
          .catch((error) => {
            console.error("更新车辆状态失败", error);
            alert("更新车辆状态失败，请重试");
          });
      } else if (currentStatus === "2") {
        axios
          .post("http://localhost:8081/car/UpdateStatus0", {
            id: this.car.id,
          })
          .then(() => {
            const currentDate = this.getCurrentTime();
            axios
              .post("http://localhost:8081/car/UpdateCFixDate", {
                id: this.car.id,
                CFixDate: currentDate,
              })
              .then(() => {
                alert("车辆状态已更新为空闲，维修日期已更新");
                this.car.CStatus = "0";
                this.car.CFixDate = currentDate;
              })
              .catch((error) => {
                console.error("更新维修日期失败", error);
                alert("更新维修日期失败，请重试");
              });
          })
          .catch((error) => {
            console.error("更新车辆状态失败", error);
            alert("更新车辆状态失败，请重试");
          });
      } else {
        alert("车辆状态无法修改");
      }
    },
    getStatusText(status) {
      switch (status) {
        case "0":
          return "空闲";
        case "1":
          return "使用中";
        case "2":
          return "维修中";
        default:
          return "未知状态";
      }
    },
    getStatusClass(status) {
      switch (status) {
        case "0":
          return "green";
        case "1":
          return "red";
        case "2":
          return "yellow";
        default:
          return "default";
      }
    },
  },
};
</script>

<style scoped>
.car-detail {
  display: flex;
  flex-direction: column;
  align-items: center;
  background-color: #f7f7f7;
  padding: 20px;
  min-height: 100vh;
}

.car-info-container {
  display: flex;
  flex-direction: column;
  gap: 30px;
  width: 100%;
  max-width: 1200px;
}

.upper-section {
  display: flex;
  justify-content: space-between;
  background-color: #ffffff;
  padding: 20px;
  border-radius: 8px;
  box-shadow: 0 2px 10px rgba(0, 0, 0, 0.1);
}

.car-info-left {
  flex: 2;
}

.car-image-container {
  flex: 1;
  display: flex;
  justify-content: center;
  align-items: center;
}
.edit-icon {
  width: 20px;
  height: 20px;
  cursor: pointer;
}

.detail-image {
  max-width: 100%;
  height: auto;
  object-fit: cover;
  border-radius: 8px;
}

.rental-history-section {
  background-color: #ffffff;
  padding: 20px;
  border-radius: 8px;
  box-shadow: 0 2px 10px rgba(0, 0, 0, 0.1);
}


.action-buttons {
  margin-top: 20px;
}

.action-button {
  display: inline-block;
  margin-right: 10px;
  padding: 10px 20px;
  font-size: 16px;
  color: #fff;
  border: none;
  border-radius: 25px;
  box-shadow: 0 2px 6px rgba(0, 0, 0, 0.15);
  cursor: pointer;
  transition: all 0.3s ease;
}

.action-button.rent {
  background-color: #28a745;
}

.action-button.return {
  background-color: #007bff;
}

.action-button.fix {
  background-color: #ffc107;
}

.action-button.delete {
  background-color: #dc3545;
}

.action-button:hover {
  transform: translateY(-2px);
  box-shadow: 0 4px 8px rgba(0, 0, 0, 0.2);
}

.status-indicator {
  display: inline-block;
  width: 12px;
  height: 12px;
  border-radius: 50%;
  margin-left: 10px;
}


.rental-table {
  width: 100%;
  border-collapse: collapse;
  margin-top: 20px;
}

.rental-table th,
.rental-table td {
  padding: 10px;
  border-bottom: 1px solid #ddd;
  text-align: left;
}

.rental-table th {
  background-color: #f0f0f0;
}

.status-indicator {
  display: inline-block;
  width: 12px;
  height: 12px;
  border-radius: 50%;
  margin-left: 10px;
}

.status-indicator.green {
  background-color: green;
}

.status-indicator.red {
  background-color: red;
}

.status-indicator.yellow {
  background-color: yellow;
}
</style>
