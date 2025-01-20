<template>
  <div class="driver-list-container">
    <!-- 筛选部分 -->
    <div class="filter-container">
      <!-- 司机状态筛选 -->
      <div class="filter-item">
        <label for="statusFilter">司机状态:</label>
        <select v-model="filters.status" id="statusFilter">
          <option value="">所有状态</option>
          <option value="1">工作中</option>
          <option value="2">请假</option>
          <option value="0">空闲</option>
        </select>
      </div>

      <!-- 驾照等级筛选 -->
      <div class="filter-item">
        <label for="levelFilter">驾照等级:</label>
        <select v-model="filters.level" id="levelFilter">
          <option value="">所有等级</option>
          <option value="A1">A1</option>
          <option value="A2">A2</option>
          <option value="B2">B2</option>
          <option value="C2">C2</option>
        </select>
      </div>

      <!-- 输入框筛选 -->
      <div class="filter-item">
        <label for="searchFilter">搜索:</label>
        <input
          type="text"
          v-model="filters.search"
          id="searchFilter"
          placeholder="身份证号、姓名"
        />
      </div>
    </div>

    <!-- 司机列表 -->
    <div v-if="filteredDrivers.length === 0">
      <p>没有符合条件的司机。</p>
    </div>
    <div v-else>
      <ul class="driver-list">
        <li
          v-for="driver in filteredDrivers"
          :key="driver.dNo"
          class="driver-item"
        >
          <div class="driver-info">
            <div><strong>身份证号:</strong> {{ driver.dNo }}</div>
            <div><strong>姓名:</strong> {{ driver.dName }}</div>
            <div><strong>入职时间:</strong> {{ driver.dDate }}</div>
            <div>
              <strong>基本工资:</strong> ¥{{ driver.dMoney.toLocaleString() }}
            </div>
            <div>
              <strong>状态:</strong> <span :class="getStatusClass(driver.dStatus)">{{ getStatusText(driver.dStatus) }}</span>
            </div>
            <div><strong>驾照级别:</strong> {{ driver.dLevel }}</div>
          </div>
          <!-- 编辑按钮 -->
          <button @click="editDriver(driver.dNo)" class="edit-button">
            编辑
          </button>
          <button @click="deleteDriver(driver.dNo)" class="delete-button">
            删除
          </button>
        </li>
      </ul>
    </div>

    <!-- 添加司机按钮 -->
    <div class="add-driver-button">
      <button @click="navigateToAddDriver">添加司机</button>
    </div>
  </div>
</template>

<script>
import axios from "axios";

export default {
  data() {
    return {
      drivers: [], // 所有司机
      filteredDrivers: [], // 筛选后的司机
      filters: {
        status: "", // 状态筛选
        level: "", // 驾照等级筛选
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
          "http://localhost:8081/drivers/alldrivers"
        );
        this.drivers = response.data;
        this.filteredDrivers = this.drivers; // 初始时显示所有司机
      } catch (error) {
        console.error("获取司机数据失败", error);
      }
    },

    // 编辑司机
    editDriver(driverId) {
      this.$router.push({
        path: "/updateDriver",
        query: { driverId: driverId },
      });
    },

    // 删除司机
    async deleteDriver(driverId) {
      const confirmDelete = confirm("确定删除该司机吗？");
      if (confirmDelete) {
        try {
          await axios.post(`http://localhost:8081/drivers/delete`, {
            dNo: driverId,
          });
          // 删除成功后，重新获取司机列表
          this.fetchDrivers();
          alert("司机删除成功");
        } catch (error) {
          console.error("删除司机失败", error);
          alert("删除司机失败");
        }
      }
    },

    // 筛选司机列表
    applyFilters() {
      this.filteredDrivers = this.drivers.filter((driver) => {
        // 筛选状态
        const statusMatch = this.filters.status
          ? driver.dStatus === this.filters.status
          : true;

        // 筛选驾照等级
        const levelMatch = this.filters.level
          ? driver.dLevel === this.filters.level
          : true;

        // 搜索框匹配身份证号或姓名
        const searchMatch = this.filters.search
          ? driver.dNo.includes(this.filters.search) ||
            driver.dName.includes(this.filters.search)
          : true;

        return statusMatch && levelMatch && searchMatch;
      });
    },

    // 状态文本转换
    getStatusText(status) {
      if (status === "1") return "工作中";
      if (status === "2") return "请假";
      return "空闲";
    },

    // 获取状态对应的CSS类
    getStatusClass(status) {
      if (status === "1") return "status-working"; // 工作中
      if (status === "2") return "status-on-leave"; // 请假
      return "status-idle"; // 空闲
    },

    // 跳转到添加司机页面
    navigateToAddDriver() {
      this.$router.push("/addDriver");
    },
  },
};
</script>

<style scoped>
/* 统一字体 */
body {
  font-family: "Inter", "Helvetica", "Arial", sans-serif;
  background-color: #f8f8f8;
  color: #333;
  margin: 0;
  padding: 0;
}

.driver-list-container {
  padding: 30px;
  background-color: #ffffff;
  box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);
  border-radius: 8px;
}

.filter-container {
  display: flex;
  flex-wrap: wrap;
  gap: 15px;
  margin-bottom: 20px;
}

.filter-item {
  display: flex;
  flex-direction: column;
  align-items: flex-start;
  width: 220px;
}

.filter-item label {
  font-size: 16px;
  font-weight: 500;
  color: #555;
  margin-bottom: 5px;
}

.filter-item select,
.filter-item input {
  padding: 10px;
  font-size: 14px;
  width: 100%;
  border: 1px solid #ddd;
  border-radius: 6px;
  background-color: #f9f9f9;
}

.filter-item select:focus,
.filter-item input:focus {
  border-color: #007bff;
  outline: none;
}

.driver-list {
  display: grid;
  grid-template-columns: repeat(auto-fill, minmax(280px, 1fr));
  gap: 20px;
}

.driver-item {
  background-color: #f1f1f1f1;
  border-radius: 8px;
  padding: 20px;
  box-shadow: 0 4px 8px rgba(0, 0, 0, 0.05);
  position: relative;
  transition: transform 0.3s ease;
}

.driver-item:hover {
  transform: scale(1.02);
}

.driver-info {
  margin-bottom: 15px;
}

.driver-info div {
  margin-bottom: 8px;
}

.edit-button,
.delete-button {
  padding: 8px 15px;
  border: none;
  border-radius: 5px;
  font-size: 14px;
  cursor: pointer;
}

.edit-button {
  background-color: #2f77ce;
  color: white;
  position: absolute;
  bottom: 10px;
  right: 10px;
}

.edit-button:hover {
  background-color: #255ea4;
}

.delete-button {
  background-color: #e74c3c;
  color: white;
  position: absolute;
  bottom: 10px;
  right: 90px;
}

.delete-button:hover {
  background-color: #c0392b;
}

.add-driver-button {
  text-align: center;
  margin-top: 20px;
}

.add-driver-button button {
  padding: 10px 20px;
  background-color: #2f77ce;
  color: white;
  border: none;
  border-radius: 6px;
  cursor: pointer;
}

.add-driver-button button:hover {
  background-color: #255ea4;
}

/* 司机状态的文本样式 */
.status-working {
  color: #ff6f61; /* 工作中：红色 */
  font-weight: bold;
}

.status-on-leave {
  color: #ffb74d; /* 请假：黄色 */
  font-weight: bold;
}

.status-idle {
  color: #81c784; /* 空闲：绿色 */
  font-weight: bold;
}
</style>
