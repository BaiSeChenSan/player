<template>
  <div id="background">
    <div class="login-container">
      <h2>登录</h2>
      <form @submit.prevent="handleLogin">
        <!-- 表示当表单的 submit 事件触发时，执行 handleLogin 方法。 -->
        <div class="form-group">
          <label for="username">用户名</label>
          <input
            type="text"
            id="username"
            v-model="username"
            placeholder="请输入用户名"
            required
          />
        </div>
        <div class="form-group2">
          <label for="password">密码</label>
          <input
            type="password"
            id="password"
            v-model="password"
            placeholder="请输入密码"
            required
          />
        </div>
        <button type="submit" class="login-btn">登录</button>
      </form>
    </div>
  </div>
</template>

<script>
import axios from "axios";

export default {
  name: "LoginForm",
  data() {
    return {
      username: "",
      password: "",
    };
  },
  methods: {
    async handleLogin() {
      if (this.username && this.password) {
        const response = await axios.get("http://localhost:8081/user/login", {
          params: {
            uname: this.username,
            password: this.password,
          },
        });

        if (response) {
          alert("success!");
          this.$router.push("/VehicleManagement"); // 登录成功跳转到首页
        } else {
          alert(response.data.message || "登录失败");
        }
      } else {
        alert("请填写完整信息");
      }
    },
    goToRegister() {
      this.$router.push("/register"); // 跳转到注册页面
    },
  },
};
</script>
<style scoped>
* {
  margin: 0;
  padding: 0;
  box-sizing: border-box; /* 确保所有元素的尺寸计算不会受到边距和内边距的影响 */
}

/* 背景设置 */
#background {
  background: url("https://images.wallpaperscraft.com/image/single/street_puddle_reflection_139688_1024x768.jpg");
  width: 100%;
  height: 100%;
  position: fixed;
  top: 0; /* 确保背景从屏幕顶部开始 */
  left: 0; /* 确保背景从屏幕左边开始 */
  right: 0; /* 确保背景填充到右边 */
  bottom: 0; /* 确保背景填充到底部 */
  background-size: cover; /* 保证背景图像完全覆盖 */
  background-position: center; /* 背景居中 */
  background-repeat: no-repeat; /* 背景不重复 */
}

/* 登录容器样式 */
.login-container {
  max-width: 500px;
  max-height: 800px;
  margin: 0 auto; /* 保证容器水平居中 */
  padding: 20px;
  background-color: rgba(255, 255, 255, 0.8); /* 设置透明背景 */
  border-radius: 8px;
  box-shadow: 0 4px 10px rgba(0, 0, 0, 0.1);
  text-align: center;
  position: relative; /* 确保登录框在背景之上 */
  top: 50%; /* 垂直居中 */
  transform: translateY(-70%); /* 居中,稍微靠上 */
}

h2 {
  margin-bottom: 20px;
  color: #333;
}

.form-group {
  margin-bottom: 15px;
  text-align: left;
}

.form-group2 {
  margin-top: 30px;
  text-align: left;
}

label {
  display: block;
  font-size: 14px;
  color: #555;
}

input {
  width: 100%;
  padding: 10px;
  border: 1px solid #ddd;
  border-radius: 4px;
  font-size: 14px;
}

input:focus {
  outline: none;
  border-color: #007bff;
}

.login-btn {
  width: 100%;
  padding: 10px;
  background-color: #007bff;
  color: white;
  border: none;
  border-radius: 4px;
  font-size: 16px;
  cursor: pointer;
  margin-top: 50px;
}

.login-btn:hover {
  background-color: #0056b3;
}

.register-link {
  margin-top: 10px;
  font-size: 14px;
}

.register-link a {
  color: #007bff;
  text-decoration: none;
}

.register-link a:hover {
  text-decoration: underline;
}
</style>
