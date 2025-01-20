<template>
  <div class="return-detail">
    <h1>填写换车信息</h1>

    <div class="info-box">
      <h2>当前租车信息：</h2>
      <div class="info">
        <p><strong>发票号:</strong> {{ rentData.invoiceNum }}</p>
        <p><strong>车牌号:</strong> {{ rentData.carnum }}</p>
        <p><strong>租车日期:</strong> {{ rentData.startTime }}</p>
        <p><strong>租车天数:</strong> {{ rentData.days }}</p>
        <p><strong>用车地点:</strong> {{ rentData.location }}</p>
        <p><strong>客户手机号:</strong> {{ rentData.phone }}</p>
        <p><strong>司机:</strong> {{ rentData.driverId }}</p>
        <p><strong>租车价格:</strong> ￥{{ rentData.unitPrice }} /天</p>
      </div>
    </div>

    <div class="info-box">
      <h2>还车信息</h2>
      <form @submit.prevent="submitReturnInfo">
        <label for="mileage">往返里程:</label>
        <input
          v-model="returnData.mileage"
          id="mileage"
          type="number"
          required
        />

        <label for="date">还车日期:</label>
        <input type="date" v-model="returnData.date" id="date" required />

        <button type="submit">提交还车信息</button>
      </form>
    </div>
  </div>
</template>

<script>
import axios from "axios";

export default {
  data() {
    return {
      rentData: {
        invoiceNum: "", // 发票号
        location: "", // 用车地点
        startTime: "", // 用车时间
        phone: "", // 客户手机号
        driverId: "", // 司机身份证号
        unitPrice: "", // 租车单价
        days: "", // 租车天数
        carnum: "", // 车牌号
      },
      returnData: {
        mileage: "",
        date: "",
      },
    };
  },
  mounted() {
    this.fetchRentInfo(); // 获取租车信息
  },
  methods: {
    // 获取租车信息
    async fetchRentInfo() {
      try {
        const carId = this.$route.params.carId;
        const carResponse = await axios.get(
          `http://localhost:8081/car/${carId}`
        );
        const carnum = carResponse.data.CNo;
        const rentResponse = await axios.get(
          `http://localhost:8081/rent/re/${carnum}`
        );

        this.rentData = {
          invoiceNum: rentResponse.data.invoiceNum,
          startTime: rentResponse.data.startTime,
          unitPrice: rentResponse.data.unitPrice,
          phone: rentResponse.data.guestphone,
          driverId: rentResponse.data.driverId,
          location: rentResponse.data.locations,
          days: rentResponse.data.rentdays,
          carnum: carnum,
        };
      } catch (error) {
        console.error("获取租车信息失败", error);
        alert("获取租车信息失败");
      }
    },

    // 提交还车信息
    async submitReturnInfo() {
      try {
        // 先提交还车信息
        await axios.post("http://localhost:8081/rent/returnCar", {
          carNum: this.rentData.carnum,
          ReturnDate: this.returnData.date,
          Tdistance: this.returnData.mileage,
        });

        // 更新车辆状态为 "可用"
        await axios.post("http://localhost:8081/car/UpdateStatus0", {
          id: this.$route.params.carId,
        });

        // 获取车辆当前的里程
        const carId = this.$route.params.carId;
        const response = await axios.get(`http://localhost:8081/car/${carId}`);
        const carDistance = response.data.CDistance || 0;

        // 更新车辆的公里数
        const totalMile = (
          parseFloat(carDistance) + parseFloat(this.returnData.mileage)
        ).toString();

        await axios.post("http://localhost:8081/car/UpdateMile", {
          id: carId,
          mile: totalMile, // 更新后的公里数
        });

        alert("还车信息更新成功");

        // 更新司机状态
        await axios.post("http://localhost:8081/drivers/UpdateStatus0", {
          dNo: this.rentData.driverId,
        });
        this.$router.push({ name: "CarDetail", params: { id: carId } });
      } catch (error) {
        console.error("提交还车信息失败", error);
        alert("提交还车信息失败");
      }
    },
  },
};
</script>

<style scoped>
.return-detail {
  width: 80%;
  margin: 0 auto;
  padding: 20px;
  box-sizing: border-box;
}

.info-box {
  background-color: rgba(0, 128, 0, 0.1); /* 绿色背景 */
  padding: 20px;
  margin-bottom: 20px;
  border-radius: 8px;
}

.info-box h2 {
  margin-bottom: 15px;
}

.info {
  display: flex;
  flex-direction: column;
}

.info p {
  margin: 5px 0;
}

form {
  display: flex;
  flex-direction: column;
  gap: 10px;
}

form label {
  font-weight: bold;
}

form input {
  padding: 8px;
  border-radius: 5px;
  border: 1px solid #ccc;
}

button {
  padding: 10px 20px;
  background-color: green;
  color: white;
  border: none;
  border-radius: 5px;
  cursor: pointer;
}

button:hover {
  background-color: darkgreen;
}
</style>
