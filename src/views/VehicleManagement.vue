<template>
  <div class="page-container">
    <!-- 筛选部分 -->
    <div class="filter-container">
      <div class="filter">
        <label for="status-filter">状态:</label>
        <select v-model="selectedStatus" id="status-filter">
          <option value="">所有</option>
          <option value="0">空闲中</option>
          <option value="1">使用中</option>
          <option value="2">维修中</option>
        </select>
      </div>

      <div class="filter">
        <label for="type-filter">车型:</label>
        <select v-model="selectedType" id="type-filter">
          <option value="">所有</option>
          <option value="A级车">A级车</option>
          <option value="B级车">B级车</option>
          <option value="SUV">SUV</option>
          <option value="MPV">MPV</option>
          <option value="中型大巴">中型大巴</option>
        </select>
      </div>

      <div class="filter">
        <label for="license-plate-filter">车牌号:</label>
        <input
          type="text"
          v-model="licensePlate"
          id="license-plate-filter"
          placeholder="请输入车牌号"
        />
      </div>

      <button @click="applyFilters">筛选</button>
    </div>

    <!-- 车辆列表部分 -->
    <div v-if="filteredCars.length === 0">
      <p>没有符合条件的车辆。</p>
    </div>
    <div v-else>
      <div class="car-list-container">
        <ul class="car-list">
          <li
            v-for="car in filteredCars"
            :key="car.id"
            :class="['car-item', getCarTypeClass(car.CType)]"
            @click="navigateToDetail(car.id)"
          >
            <div class="car-item-container">
              <img :src="getCarImage(car.CNo)" alt="车辆图片" class="car-image" />
              <div class="car-info">
                <div class="status">
                  <span :class="['status-indicator', getStatusClass(car.CStatus)]"></span>
                  <strong>{{ getStatusText(car.CStatus) }}</strong>
                </div>
                <div class="car-details">
                  <span><strong>品牌:</strong> {{ car.CBrand }}</span>
                  <span><strong>型号:</strong> {{ car.CModel }}</span>
                  <span><strong>车牌号:</strong> {{ car.CNo }}</span>
                  <span><strong>类型:</strong> {{ car.CType }}</span>
                  <span><strong>购买日期:</strong> {{ car.CBuyDate }}</span>
                  <span><strong>购买价格:</strong> ¥{{ car.CPrice.toLocaleString() }}</span>
                  <span><strong>上次维修日期:</strong> {{ car.CFixDate }}</span>
                  <span><strong>行驶公里数:</strong> {{ car.CDistance }} km</span>
                  <span><strong>租车价格:</strong>¥{{ car.CUnit }}/天</span>
                </div>
              </div>
            </div>
          </li>
        </ul>
      </div>
    </div>

    <!-- 添加车辆按钮 -->
    <div class="add-car-button">
      <button @click="navigateToAddCar">添加车辆</button>
    </div>
  </div>
</template>

<script>
import axios from "axios";

export default {
  data() {
    return {
      cars: [],
      filteredCars: [],
      selectedStatus: "",
      selectedType: "",
      licensePlate: "",
    };
  },
  mounted() {
    this.fetchCars();
  },
  methods: {
    async fetchCars() {
      try {
        const response = await axios.get("http://localhost:8081/car/getcars", {
          withCredentials: true,
        });
        this.cars = response.data;
        this.filteredCars = this.cars;
      } catch (error) {
        console.error("获取车辆数据失败", error);
      }
    },

    getCarTypeClass(cType) {
      switch (cType) {
        case "SUV":
          return "suv";
        case "MPV":
          return "MPV";
        case "B级车":
          return "B级车";
        case "A级车":
          return "A级车";
        default:
          return "default";
      }
    },

    getCarImage() {
      return `https://images.wallpaperscraft.com/image/single/bmw_csl_hommage_105056_800x600.jpg`;
    },

    applyFilters() {
      let filtered = this.cars;

      if (this.selectedStatus) {
        filtered = filtered.filter((car) => car.CStatus.toString() === this.selectedStatus);
      }

      if (this.selectedType) {
        filtered = filtered.filter((car) => car.CType === this.selectedType);
      }

      if (this.licensePlate) {
        filtered = filtered.filter((car) => car.CNo.includes(this.licensePlate));
      }

      this.filteredCars = filtered;
    },

    navigateToDetail(carId) {
      this.$router.push(`/car/${carId}`);
    },

    navigateToAddCar() {
      this.$router.push("/addCar");
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
/* 使用现代字体 */
body {
  font-family: 'Inter', sans-serif;
  background-color: #f8f8f8; /* 页面背景为淡灰色 */
  color: #333;
  margin: 0;
  padding: 0;
}

.page-container {
  max-width: 1600px;
  height: 10000px;
  margin: 0 auto;
  padding: 20px;
  background-color: #ffffff; /* 页面主要区域的白色背景 */
  border-radius: 10px; /* 给页面容器加上圆角效果 */
}

.car-list-container {
  margin-top: 20px;
}

.car-list {
  list-style: none;
  padding: 0;
}

.car-item {
  display: flex;
  align-items: center;
  margin-bottom: 15px;
  border-radius: 8px;
  background-color: rgba(0, 0, 0, 0.05); /* 背景色加淡灰 */
  padding: 20px;
  box-shadow: 0 2px 10px rgba(0, 0, 0, 0.1); /* 增加阴影效果 */
}

.car-item-container {
  display: flex;
  flex: 1;
  justify-content: space-between;
}

.car-item.suv {
  background-color: rgba(86, 185, 127, 0.1);
}

.car-item.MPV {
  background-color: rgba(204, 89, 129, 0.1);
}

.car-item.B级车 {
  background-color: rgba(87, 139, 235, 0.1);
}

.car-item.A级车 {
  background-color: rgba(168, 137, 101, 0.1);
}

.car-item.default {
  background-color: rgba(19, 159, 89, 0.1);
}

.car-image {
  width: 120px;
  height: 80px;
  object-fit: cover;
  margin-right: 20px;
  border-radius: 8px;
}

.car-info {
  flex: 1;
}

.status {
  display: flex;
  align-items: center;
  margin-bottom: 15px;
}

.status-indicator {
  width: 12px;
  height: 12px;
  border-radius: 50%;
  margin-right: 10px;
}

.status-indicator.green {
  background-color: #4caf50;
}

.status-indicator.red {
  background-color: #f44336;
}

.status-indicator.yellow {
  background-color: #ffeb3b;
}

.car-details {
  display: flex;
  flex-wrap: wrap;
  gap: 20px;
  line-height: 1.6;
}

.filter-container {
  display: flex;
  flex-wrap: wrap;
  gap: 20px;
  margin-bottom: 30px;
}

.filter {
  display: flex;
  flex-direction: column;
  align-items: flex-start;
}

.filter label {
  font-size: 14px;
  font-weight: 500;
  color: #333;
}

select,
input {
  padding: 10px;
  font-size: 14px;
  border: 1px solid #ffffff;
  border-radius: 6px;
  background-color: #ffffff;
  border: 1px solid #ccc; /* 设置默认的边框颜色 */
}

button {
  padding: 10px 20px;
  background-color: #2f77ce;
  color: white;
  border: none;
  border-radius: 5px;
  cursor: pointer;
  height: 40px;
  margin-top: 16px;
}

button:hover {
  background-color: #0056b3;
}

.add-car-button {
  margin-top: 20px;
  text-align: center;
}
</style>
