<template>
  <div class="page-container">
    <div class="driver-list-container">
      <!-- 筛选部分 -->
      <div class="filter-container">
        <!-- 输入框筛选 -->
        <div class="filter-item">
          <label for="searchFilter">搜索:</label>
          <input
            type="text"
            v-model="filters.search"
            id="searchFilter"
            placeholder="手机号、姓名"
          />
        </div>
      </div>

      <!-- 客户列表 -->
      <div v-if="filteredDrivers.length === 0">
        <p>没有符合条件的司机。</p>
      </div>
      <div v-else>
        <ul class="driver-list">
          <li
            v-for="guest in filteredDrivers"
            :key="guest.phoneNum"
            class="driver-item"
            :style="{}"
          >
            <div class="driver-info">
              <div><strong>手机号:</strong> {{ guest.phoneNum }}</div>
              <div><strong>姓名:</strong> {{ guest.name }}</div>
              <div><strong>工作地址:</strong> {{ guest.workAddr }}</div>
              <div><strong>家庭地址:</strong> {{ guest.liveAddr }}</div>
              <div><strong>邮政编码:</strong> {{ guest.code }}</div>
            </div>
            <!-- 编辑按钮 -->
            <button @click="editDriver(guest.phoneNum)" class="edit-button">
              编辑
            </button>
            <button @click="deleteDriver(guest.phoneNum)" class="delete-button">
              删除
            </button>
          </li>
        </ul>
      </div>

      <!-- 添加司机按钮 -->
      <div class="add-driver-button">
        <button @click="navigateToAddDriver">添加客户</button>
      </div>
    </div>
  </div>
</template>

<script>
import axios from "axios";

export default {
  data() {
    return {
      guest: [], // 所有司机
      filteredDrivers: [], // 筛选后的司机
      filters: {
        search: "", // 搜索框
      },
    };
  },
  mounted() {
    this.fetchDrivers();
  },
  watch: {
    filters: {
      handler() {
        this.applyFilters();
      },
      deep: true,
    },
  },
  methods: {
    // 获取司机数据
    async fetchDrivers() {
      try {
        const response = await axios.get(
          "http://localhost:8081/guest/allguests"
        );
        this.guest = response.data;
        this.filteredDrivers = this.guest; // 初始时显示所有司机
      } catch (error) {
        console.error("获取司机数据失败", error);
      }
    },

    // 编辑司机
    editDriver(driverId) {
      this.$router.push({
        path: "/updateGuest",
        query: { phoneNum: driverId },
      });
    },

    // 删除司机
    async deleteDriver(driverId) {
      const confirmDelete = confirm("确定删除该客户信息吗？");
      if (confirmDelete) {
        try {
          await axios.post(`http://localhost:8081/guest/deleteguest`, {
            phoneNum: driverId,
          });
          // 删除成功后，重新获取司机列表
          this.fetchDrivers();
          alert("客户删除成功");
        } catch (error) {
          console.error("删除司机失败", error);
          alert("客户删除失败");
        }
      }
    },

    // 筛选司机列表
    applyFilters() {
      this.filteredDrivers = this.guest.filter((guest) => {
        // 搜索框匹配手机号或姓名
        const searchMatch = this.filters.search
          ? guest.phoneNum.includes(this.filters.search) ||
            guest.name.includes(this.filters.search)
          : true;
        return searchMatch;
      });
    },

    // 状态文本转换
    getStatusText(status) {
      if (status === "1") return "工作中";
      if (status === "2") return "请假";
      return "空闲";
    },

    // 根据司机状态返回背景色
    getStatusColor(status) {
      switch (status) {
        default:
          return "rgba(60, 179, 113, 0.2)"; // 空闲：MediumSeaGreen
      }
    },

    // 跳转到添加客户页面
    navigateToAddDriver() {
      this.$router.push("/addGuest");
    },
  },
};
</script>

<style>
/* 整个页面背景色 */
.page-container {
  background-color: white; /* 白色背景 */
  padding: 20px; /* 给容器添加内边距 */
  border-radius: 8px; /* 可选：圆角效果 */
  box-shadow: 0px 4px 10px rgba(0, 0, 0, 0.1); /* 给容器加个轻微的阴影 */
  margin: 0px auto; /* 页面居中显示 */
  max-width: 1600px; /* 最大宽度，防止内容过宽 */
  height: 100vh; /* 高度为视口高度 */
}

/* 强制将整个页面背景设为灰色 */
html, body {
  margin: 0;
  padding: 0;
  height: 100%;
  background-color: rgb(241, 241, 241) !important; /* 强制设置背景为灰色 */
}

/* 背景和容器设置 */
.driver-list-container {
  min-height: 100vh;
  font-family: 'Roboto', sans-serif; /* 使用更现代的字体 */
  color:#D3D3D3; /* 默认字体颜色 */
}

/* 筛选部分 */
.filter-container {
  margin-bottom: 30px;
  display: flex;
  justify-content: flex-start;
  gap: 20px;
}

.filter-item {
  display: flex;
  flex-direction: column;
  width: 250px;
}

.filter-item label {
  font-size: 16px;
  font-weight: 500;
  color: #555;
  margin-bottom: 8px;
}

.filter-item input {
  padding: 10px;
  border-radius: 8px;
  border: 1px solid #b1afaf;
  font-size: 16px;
}

.filter-item input:focus {
  outline: none;
  border-color: #0078d4; /* 蓝色边框 */
}

/* 司机列表 */
.driver-list {
  list-style: none;
  padding: 0;
  display: grid;
  grid-template-columns: repeat(auto-fill, minmax(350px, 1fr));
  gap: 20px;
  background-color: #ffffff;
}

.driver-item {
  position: relative; /* 添加相对定位 */
  background-color: #f1f1f1;
  border-radius: 10px;
  padding: 20px;
  box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
  transition: transform 0.3s, box-shadow 0.3s;
}

.driver-item:hover {
  transform: translateY(-10px);
  box-shadow: 0 8px 16px rgba(0, 0, 0, 0.15);
}

.driver-info {
  margin-bottom: 15px;
  font-size: 14px;
  color: #555;
}

.driver-info div {
  margin-bottom: 8px;
}

.edit-button,
.delete-button {
  position: absolute; /* 绝对定位 */
  bottom: 20px; /* 距离底部 20px */
  padding: 8px 15px;
  border-radius: 5px;
  font-size: 14px;
  color: #fff;
  border: none;
  cursor: pointer;
}

.edit-button {
  background-color: #0078d4; /* 蓝色按钮 */
  right: 20px; /* 距离右侧 20px */
}

.delete-button {
  background-color: #e74c3c; /* 红色按钮 */
  right: 100px; /* 距离右侧 100px */
}

.edit-button:hover {
  background-color: #006bb3;
}

.delete-button:hover {
  background-color: #c0392b;
}

/* 添加司机按钮 */
.add-driver-button {
  margin-top: 40px;
  text-align: center;
}

button {
  padding: 10px 20px;
  background-color: #3498db;
  color: white;
  border: none;
  border-radius: 5px;
  font-size: 16px;
  cursor: pointer;
}

button:hover {
  background-color: #2980b9;
}

@media (max-width: 768px) {
  .filter-container {
    flex-direction: column;
    align-items: stretch;
  }
  
  .filter-item {
    width: 100%;
    margin-bottom: 15px;
  }

  .driver-list {
    grid-template-columns: 1fr;
  }
}
</style>
