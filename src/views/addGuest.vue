<template>
  <div class="add-driver-container">
    <h2>添加客户</h2>

    <!-- 表单部分 -->
    <form @submit.prevent="submitDriver">
      <div class="form-group">
        <label for="phoneNum">手机号:</label>
        <input
          v-model="driver.phoneNum"
          type="text"
          id="phoneNum"
          placeholder="请输入客户手机号"
          required
        />
      </div>

      <div class="form-group">
        <label for="name">姓名:</label>
        <input
          v-model="driver.name"
          type="text"
          id="name"
          placeholder="请输入客户姓名"
          required
        />
      </div>

      <div class="form-group">
        <label for="wordAddr">工作地址:</label>
        <input v-model="driver.wordAddr" type="text" id="wordAddr" required />
      </div>

      <div class="form-group">
        <label for="liveAddr">家庭住址:</label>
        <input
          v-model.number="driver.liveAddr"
          type="text"
          id="liveAddr"
          placeholder="请输入客户家庭住址"
          required
        />
      </div>

      <div class="form-group">
        <label for="code">邮政编码:</label>
        <input
          v-model.number="driver.code"
          type="number"
          id="code"
          placeholder="请输入客户邮编"
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
        phoneNum: "", // 手机号
        name: "", // 姓名
        wordAddr: "",
        liveAddr: null,
        code: "",
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
          "http://localhost:8081/guest/addGuest",
          this.driver
        );

        if (response.status === 200) {
          this.submitSuccess = true; // 提交成功
          alert("添加客户业务成功");
          this.resetForm(); // 重置表单
          this.$router.push({ name: "GuestManagement" });
        }
      } catch (error) {
        console.error("提交失败", error);
        this.submitError = true; // 提交失败
      }
    },

    // 重置表单数据
    resetForm() {
      this.driver = {
        phoneNum: "", // 手机号
        name: "", // 姓名
        wordAddr: "",
        liveAddr: null,
        code: "",
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
