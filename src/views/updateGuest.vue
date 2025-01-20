<template>
  <div class="update-driver-container">
    <h2>编辑司机</h2>

    <!-- 表单部分 -->
    <form @submit.prevent="submitDriver">
      <div class="form-group">
        <label for="phoneNum">身份证号:</label>
        <!-- 身份证号也可以修改 -->
        <input v-model="driver.phoneNum" type="text" id="phoneNum" required />
      </div>

      <div class="form-group">
        <label for="name">姓名:</label>
        <input v-model="driver.name" type="text" id="name" required />
      </div>

      <div class="form-group">
        <label for="workAddr">工作地址:</label>
        <input v-model="driver.workAddr" type="text" id="workAddr" required />
      </div>

      <div class="form-group">
        <label for="liveAddr">家庭住址:</label>
        <input v-model="driver.liveAddr" type="text" id="liveAddr" required />
      </div>

      <div class="form-group">
        <label for="code">邮政编码:</label>
        <input v-model="driver.code" type="text" id="code" required />
      </div>

      <!-- 提交按钮 -->
      <button type="submit" class="submit-button">提交</button>
    </form>

    <!-- 提交反馈 -->
    <p v-if="submitSuccess" class="success-message">司机信息提交成功！</p>
    <p v-if="submitError" class="error-message">提交失败，请重试。</p>
  </div>
</template>

<script>
import axios from "axios";

export default {
  data() {
    return {
      driver: {
        phoneNum: "", // 手机号
        name: "", // 姓名
        workAddr: "",
        liveAddr: null,
        code: "",
      },
      submitSuccess: false, // 提交成功状态
      submitError: false, // 提交失败状态
    };
  },
  mounted() {
    // 页面加载时通过路由参数获取司机ID并请求司机数据
    this.fetchDriverDetails(this.$route.query.phoneNum);
  },
  methods: {
    // 获取司机信息
    async fetchDriverDetails(driverdNo) {
      try {
        // 请求后端 API 获取司机数据
        //alert(driverdNo);
        const response = await axios.get(
          `http://localhost:8081/guest/${driverdNo}`
        );
        // 将数据填充到 driver 对象中，表单字段会自动更新
        this.driver = response.data;
      } catch (error) {
        console.error("获取司机信息失败", error);
        this.submitError = true;
      }
    },

    // 提交编辑后的司机信息
    async submitDriver() {
      try {
        this.submitSuccess = false;
        this.submitError = false;

        // 向后端发送 get 请求进行更新
        const response = await axios.post(
          `http://localhost:8081/guest/addGuest`,
          this.driver
        );
        if (response.status === 200) {
          this.submitSuccess = true; // 提交成功
          alert("编辑成功");
          this.$router.push({ name: "GuestManagement" }); // 跳转到司机管理页面
        }
      } catch (error) {
        console.error("提交失败", error);
        this.submitError = true; // 提交失败
      }
    },
  },
};
</script>

<style scoped>
.update-driver-container {
  max-width: 400px;
  margin: 0 auto;
  padding: 20px;
  border: 1px solid #ccc;
  border-radius: 10px;
  background-color: #f9f9f9;
}

h2 {
  text-align: center;
  color: #333;
}

.form-group {
  margin-bottom: 15px;
}

label {
  display: block;
  margin-bottom: 5px;
  font-weight: bold;
  color: #555;
}

input,
select {
  width: 100%;
  padding: 8px;
  box-sizing: border-box;
  border: 1px solid #ccc;
  border-radius: 5px;
}

button.submit-button {
  width: 100%;
  padding: 10px;
  background-color: #0078d4;
  color: white;
  border: none;
  border-radius: 5px;
  font-size: 16px;
  cursor: pointer;
}

button.submit-button:hover {
  background-color: #005ea6;
}

.success-message {
  color: green;
  text-align: center;
  margin-top: 10px;
}

.error-message {
  color: red;
  text-align: center;
  margin-top: 10px;
}
</style>
