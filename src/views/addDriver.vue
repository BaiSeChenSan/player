<template>
  <div class="add-driver-container">
    <h2>添加司机</h2>

    <!-- 表单部分 -->
    <form @submit.prevent="submitDriver">
      <div class="form-group">
        <label for="dNo">身份证号:</label>
        <input
          v-model="driver.dNo"
          type="text"
          id="dNo"
          placeholder="请输入身份证号"
          required
        />
      </div>

      <div class="form-group">
        <label for="dName">姓名:</label>
        <input
          v-model="driver.dName"
          type="text"
          id="dName"
          placeholder="请输入姓名"
          required
        />
      </div>

      <div class="form-group">
        <label for="dDate">入职时间:</label>
        <input v-model="driver.dDate" type="date" id="dDate" required />
      </div>

      <div class="form-group">
        <label for="dMoney">基本工资:</label>
        <input
          v-model.number="driver.dMoney"
          type="number"
          id="dMoney"
          placeholder="请输入基本工资"
          required
        />
      </div>

      <div class="form-group">
        <label for="dStatus">状态:</label>
        <select v-model="driver.dStatus" id="dStatus" required>
          <option value="0">空闲</option>
          <option value="1">工作中</option>
          <option value="2">请假</option>
        </select>
      </div>

      <div class="form-group">
        <label for="dLevel">驾照级别:</label>
        <input
          v-model="driver.dLevel"
          type="text"
          id="dLevel"
          placeholder="请输入驾照级别"
          required
        />
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
        dNo: "", // 身份证号
        dName: "", // 姓名
        dDate: "", // 入职时间
        dMoney: null, // 基本工资
        dStatus: "0", // 状态: 默认空闲
        dLevel: "", // 驾照级别
      },
      submitSuccess: false, // 提交成功状态
      submitError: false, // 提交失败状态
    };
  },
  methods: {
    // 提交司机信息
    async submitDriver() {
      try {
        this.submitSuccess = false;
        this.submitError = false;

        // 向后端发送 POST 请求
        const response = await axios.post(
          "http://localhost:8081/drivers/addDriverr",
          this.driver
        );

        if (response.status === 200) {
          this.submitSuccess = true; // 提交成功
          alert("添加司机成功");
          this.resetForm(); // 重置表单
          this.$router.push({ name: "DriverManagement" });
        }
      } catch (error) {
        console.error("提交失败", error);
        this.submitError = true; // 提交失败
      }
    },

    // 重置表单数据
    resetForm() {
      this.driver = {
        dNo: "",
        dName: "",
        dDate: "",
        dMoney: null,
        dStatus: "0",
        dLevel: "",
      };
    },
  },
};
</script>

<style scoped>
.add-driver-container {
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
