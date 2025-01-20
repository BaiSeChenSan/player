<template>
  <div class="rent-detail">
    <h1>填写出租信息</h1>
    <form @submit.prevent="submitRentInfo">
      <!-- 车牌号 -->
      <label for="carnum">车牌号:</label>
      <input v-model="rentData.carnum" id="carnum" readonly />

      <!-- 租车单价 -->
      <label for="unitPrice">租车单价（￥/天）:</label>
      <input
        v-model="rentData.unitPrice"
        id="unitPrice"
        type="number"
        readonly
      />

      <!-- 发票号 -->
      <label for="invoice">订单号:</label>
      <input v-model="rentData.invoiceNum" id="invoice" required />

      <!-- 用车地点 -->
      <label for="location">用车地点:</label>
      <input v-model="rentData.location" id="location" required />

      <!-- 用车时间 -->
      <label for="startTime">用车时间:</label>
      <input
        type="datetime-local"
        v-model="rentData.startTime"
        id="startTime"
        required
      />

      <!-- 客户手机号 -->
      <label for="phone">客户手机号:</label>
      <input type="tel" v-model="rentData.phone" id="phone" required />

      <div>
        <!-- 司机身份证号 -->
        <label for="driverId">司机身份证号:</label>
        <select v-model="rentData.driverId" id="driverId" required>
          <option disabled value="">请选择司机身份证号</option>
          <option
            v-for="(content, index) in driverOptions"
            :key="index"
            :value="content"
          >
            {{ content }}
          </option>
        </select>
      </div>

      <!-- 租车天数 -->
      <label for="days">租车天数:</label>
      <input type="number" v-model="rentData.days" id="days" required />

      <button type="submit">提交出租信息</button>
    </form>
  </div>
</template>

<script>
import axios from 'axios';
export default {
  data() {
    return {
      rentData: {
        invoiceNum: "", // 订单号
        location: "", // 用车地点
        startTime: "", // 用车时间
        phone: "", // 客户手机号
        driverId: "", // 司机身份证号
        unitPrice: "", // 租车单价
        days: "", // 租车天数
        carnum: "", // 车牌号
      },
      driverOptions: [], // 用来存储从后端获取的司机列表
    };
  },
  methods: {
    async fetchDriverOptions() {
      try {
        const response = await axios.get(
          "http://localhost:8081/drivers/allFreedrivers"
        );
        this.driverOptions = response.data; // 将后端返回的司机列表赋值给 driverOptions
      } catch (error) {
        console.error("获取司机列表失败", error);
      }
    },
    async submitRentInfo() {
      // 提交租车信息
      await axios.post(
        "http://localhost:8081/rent/addRent",
        {
          invoiceNum: this.rentData.invoiceNum,
          locations: this.rentData.location,
          startTime: this.rentData.startTime,
          guestphone: this.rentData.phone,
          driverId: this.rentData.driverId,
          unitPrice: this.rentData.unitPrice,
          rentdays: this.rentData.days,
          CarNum: this.rentData.carnum, // 确保是 CarNum
        }
      );
      //alert(this.rentData.carnum);
      // 更新车辆状态
      await axios.post("http://localhost:8081/car/UpdateStatus1", {
        id: this.$route.params.carId,
      });
      //alert(this.rentData.driverId);
      // 更新司机状态
      await axios.post("http://localhost:8081/drivers/UpdateStatus1", {
        dNo: this.rentData.driverId,
      });

      alert("添加租车业务成功");
      // 跳转到汽车详情页
      this.$router.push({
        name: "CarDetail",
        params: { id: this.$route.params.carId },
      });
    },
  },
  async mounted() {
    try {
      this.fetchDriverOptions();
      // 获取 carId
      const carId = this.$route.params.carId;

      // 发起请求获取车牌号和租车单价
      const response = await axios.get(`http://localhost:8081/car/${carId}`);
      const carData = response.data;

      // 将车牌号和租车单价填充到租车信息中
      this.rentData.carnum = carData.CNo;
      this.rentData.unitPrice = carData.CUnit;

      // 打印到控制台，确认数据已加载
      console.log("车牌号:", this.rentData.carnum);
      console.log("租车单价:", this.rentData.unitPrice);
    } catch (error) {
      console.error("获取车信息失败", error);
    }
  },
};
</script>

<style scoped>
/* 页面样式 */
.rent-detail {
  width: 80%;
  margin: 0 auto;
  padding: 20px;
  box-sizing: border-box;
}

form {
  display: flex;
  flex-direction: column;
  gap: 15px;
}
label {
  font-size: 16px;
  display: block; /* 让 label 占一整行 */
  margin-bottom: 8px; /* 让 label 和下拉框之间有一定的间距 */
}

/* 下拉框样式 */
select {
  width: 100%; /* 让下拉框宽度自动填满父容器 */
  padding: 10px;
  font-size: 16px;
  border: 1px solid #ccc;
  border-radius: 5px;
  margin-top: 20px; /* 让下拉框和下面的内容有间距 */
}

input {
  padding: 10px;
  font-size: 16px;
  border: 1px solid #ccc;
  border-radius: 5px;
}

button {
  padding: 10px 20px;
  margin-top: 20px;
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
