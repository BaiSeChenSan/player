<template>
  <div class="content">
    <div id="app">
      <!-- 导航栏 -->
      <nav v-if="userLoggedIn">
        <header class="navbar">
          <h1>皮斯长途汽车公司</h1>
          <nav>
            <ul>
              <li
                @click="navigateTo('VehicleManagement')"
                :class="[
                  'nav-item',
                  { active: currentPage === 'VehicleManagement' },
                ]"
                :disabled="currentPage === 'VehicleManagement'"
              >
                车辆管理
              </li>
              <select
                v-model="selectedOption"
                @change="handleSelectChange"
                class="custom-select"
              >
                <option value="default" disabled selected hidden>
                  人员管理
                </option>
                <option value="DriverManagement" @click="navigateTo(value)">
                  司机管理
                </option>
                <option value="GuestManagement" @click="navigateTo(value)">
                  客户管理
                </option>
              </select>
              <li
                @click="navigateTo('OrderCenter')"
                :class="['nav-item', { active: currentPage === 'OrderCenter' }]"
                :disabled="currentPage === 'OrderCenter'"
              >
                业务管理
              </li>
              <li
                @click="navigateTo('MoneyManagement')"
                :class="[
                  'nav-item',
                  { active: currentPage === 'MoneyManagement' },
                ]"
                :disabled="currentPage === 'MoneyManagement'"
              >
                收支管理
              </li>
            </ul>
          </nav>
        </header>
      </nav>

      <!-- 路由显示区域 -->
      <div class="content-area">
        <router-view />
      </div>

      <!-- 半透明遮罩层 -->
      <div v-if="currentPage === 'VehicleManagement'" class="overlay"></div>
      <div v-if="currentPage === 'DriverManagement'" class="overlay"></div>
    </div>
  </div>
</template>

<script>
export default {
  data() {
    return {
      userLoggedIn: true, // 假设用户已登录
      currentPage: "VehicleManagement", // 默认界面是车辆管理
      selectedOption: "default", // 初始选项是 "default" 即未选择
    };
  },
  watch: {
    // 监听路由变化
    $route(to) {
      if (to.name === "Login") {
        this.userLoggedIn = false; // 登录界面时隐藏导航栏
      } else {
        this.userLoggedIn = true; // 登录成功后，显示导航栏
        this.updateCurrentPage(to.name); // 更新当前页面状态
      }
    },
  },
  methods: {
    handleSelectChange() {
      if (this.selectedOption !== "default") {
        this.navigateTo(this.selectedOption);
        this.selectedOption = "default"; // 重置为第一个选项
      }
    },
    // 跳转页面并更新当前页面状态
    navigateTo(page) {
      if (page !== this.currentPage) {
        // 防止重复点击
        this.$router.push({ name: page });
        this.updateCurrentPage(page);
      }
    },

    // 更新当前页面
    updateCurrentPage(page) {
      this.currentPage = page;
    },
  },
};
</script>

<style scoped>
html,
body {
  margin: 0;
  padding: 0;
  font-family: "Segoe UI", "Roboto", Arial, sans-serif; /* 替换字体 */
  color: #333; /* 主文字颜色 */
  line-height: 1.6; /* 行间距增加 */
}
.content {
  height: 1000px;
}

/* 导航栏样式 */
.navbar {
  display: flex;
  justify-content: space-between;
  align-items: center;
  background-color: #0078d4;
  color: white;
  padding: 1rem;
}

.navbar ul {
  list-style: none;
  display: flex;
  gap: 1rem;
  margin: 0;
  padding: 0;
}

.navbar li {
  cursor: pointer;
  font-weight: bold;
  padding: 0.5rem 1rem;
  border-radius: 5px;
}

.navbar li:disabled {
  cursor: not-allowed;
  opacity: 0.5;
}

.navbar li.active {
  background-color: #006bb3;
  color: white;
}

/* 内容区域 */
.content-area {
  padding: 20px;
  position: relative; /* 保证遮罩层覆盖内容 */
}
.custom-select {
  background-color: #0078d4; /* 背景颜色 */
  color: white; /* 文字颜色 */
  font-weight: bold;
  font-size: medium;
  border: 1px solid #0078d4; /* 边框颜色 */
  border-radius: 5px; /* 圆角 */
  padding: 5px 10px; /* 内边距 */
  width: 105px;
  outline: none;
}

/* 鼠标悬浮时改变颜色 */
.custom-select:hover {
  background-color: #005fa3;
  box-shadow: 0px 4px 10px rgba(36, 94, 158,  0.3); /* 阴影样式 */
}

.navbar li:hover {
  box-shadow: 0px 4px 10px rgba(36, 94, 158, 0.3); /* 阴影效果 */
  background-color: #005fa3; /* 悬浮时的背景颜色 */
}

/* 点击时激活的样式 */
.navbar li.active {
  background-color: #006bb3;
  color: white;
  box-shadow: 0px 4px 10px rgba(36, 94, 158, 0.3); /* 添加阴影 */
}

.custom-select option[hidden] {
  display: none; /* 隐藏默认选项 */
}

/* 默认页面载入样式 */
body {
  position: relative;
}
html, body {
  margin: 0;
  padding: 0;
  background-color: 	#ffffff;
  font-family: Arial, sans-serif; /* 可选字体 */
}
</style>
