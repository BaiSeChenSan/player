<template>
  <div class="content">
    <!-- 筛选部分 -->
    <div class="filter-container">
      <!-- 时间段筛选 -->
      <div class="filter">
        <label for="start-time-filter">租车时间：</label>
        <input
          type="date"
          v-model="startTimeFilter"
          id="start-time-filter"
          placeholder="开始日期"
        />
        <label for="end-time-filter">至：</label>
        <input
          type="date"
          v-model="endTimeFilter"
          id="end-time-filter"
          placeholder="结束日期"
        />
      </div>

      <!-- 输入信息筛选 -->
      <div class="filter">
        <label for="info-filter">输入信息:</label>
        <input
          type="text"
          v-model="infoFilter"
          id="info-filter"
          placeholder="车牌号、手机号或用车地点"
        />
      </div>

      <!-- 筛选按钮 -->
      <button @click="applyFilters">筛选</button>
    </div>

    <!-- 租车业务列表 -->
    <div v-if="filteredRents.length === 0">
      <p>没有符合条件的租车业务。</p>
    </div>
    <div v-else>
      <ul class="rent-list">
        <li
          v-for="rent in filteredRents"
          :key="rent.invoiceNum"
          class="rent-item"
        >
          <div class="rent-info">
            <!-- 订单信息部分 -->
            <div class="order-info">
              <h4>订单信息</h4>
              <p><strong>订单号:</strong> {{ rent.invoiceNum }}</p>
              <p><strong>用车地点:</strong> {{ rent.locations }}</p>
              <p><strong>租车时间:</strong> {{ rent.startTime }}</p>
              <p><strong>租车天数:</strong> {{ rent.rentdays }} 天</p>
              <p><strong>租车单价:</strong> ¥{{ rent.unitPrice }}</p>
              <p><strong>应付金额:</strong> ¥{{ rent.tmoney }}</p>
              <p><strong>车牌号:</strong> {{ rent.carNum }}</p>
              <p><strong>司机:</strong> {{ rent.driverId }}</p>
              <p><strong>还车时间:</strong> {{ rent.returnDate || "暂未归还" }}</p>
            </div>

            <!-- 分隔线 -->
            <div class="separator"></div>

            <!-- 客户信息部分 -->
            <div v-if="rent.guestphone" class="customer-info">
              <h4>客户信息</h4>
              <p><strong>客户手机号:</strong> {{ rent.guestphone }}</p>
              <p v-if="rent.customerInfo">
                <strong>客户姓名:</strong> {{ rent.customerInfo.name }}
              </p>
              <p v-if="rent.customerInfo">
                <strong>工作地址:</strong> {{ rent.customerInfo.workAddr }}
              </p>
              <p v-if="rent.customerInfo">
                <strong>住址:</strong> {{ rent.customerInfo.liveAddr || '暂无地址' }}
              </p>
              <p v-if="rent.customerInfo">
                <strong>客户编码:</strong> {{ rent.customerInfo.code }}
              </p>
            </div>
          </div>
        </li>
      </ul>
    </div>
  </div>
</template>

<script>
import axios from "axios";

export default {
  data() {
    return {
      rents: [], // 所有租车业务
      filteredRents: [], // 筛选后的租车业务
      startTimeFilter: "", // 用车开始时间筛选
      endTimeFilter: "", // 用车结束时间筛选
      infoFilter: "", // 输入信息筛选（车牌号或手机号）
    };
  },
  mounted() {
    this.fetchRents();
  },
  methods: {
    // 获取租车业务数据
    async fetchRents() {
      try {
        const response = await axios.get(
          "http://localhost:8081/rent/getAllRents",
          { withCredentials: true }
        );
        this.rents = response.data;
        await this.fetchCustomerInfo(); // 获取每个客户信息
        this.filteredRents = this.rents; // 初始时显示所有租车业务
      } catch (error) {
        console.error("获取租车业务数据失败", error);
      }
    },

    // 获取客户信息并更新租车业务列表
    async fetchCustomerInfo() {
      for (let rent of this.rents) {
        if (rent.guestphone) {
          try {
            const response = await axios.get(
              `http://localhost:8081/guest/${rent.guestphone}`,
              { withCredentials: true }
            );
            rent.customerInfo = response.data; // 将客户信息绑定到租车业务
          } catch (error) {
            console.error(`获取客户信息失败: ${rent.guestphone}`, error);
          }
        }
      }
    },

    // 筛选租车业务列表
    applyFilters() {
      let filtered = this.rents;

      if (this.startTimeFilter && this.endTimeFilter) {
        filtered = filtered.filter((rent) => {
          const rentStartTime = new Date(rent.startTime);
          const filterStartTime = new Date(this.startTimeFilter);
          const filterEndTime = new Date(this.endTimeFilter);

          filterStartTime.setHours(0, 0, 0, 0);
          filterEndTime.setHours(23, 59, 59, 999);

          return (
            rentStartTime >= filterStartTime && rentStartTime <= filterEndTime
          );
        });
      }

      if (this.infoFilter) {
        filtered = filtered.filter(
          (rent) =>
            rent.carNum.includes(this.infoFilter) ||
            rent.guestphone.includes(this.infoFilter) ||
            rent.locations.includes(this.infoFilter)
        );
      }

      this.filteredRents = filtered;
    },

    // 跳转到租车详情页面
    navigateToDetail(invoiceNum) {
      this.$router.push(`/rent/${invoiceNum}`);
    },
  },
};
</script>

<style scoped>
.content {
  margin: 20px;
}

/* 样式部分 */
.rent-list {
  list-style: none;
  padding: 0;
}

.rent-item {
  padding: 20px;
  margin-bottom: 15px;
  border-radius: 8px;
  border: 1px solid #ddd;
  cursor: pointer;
  background-color: #f9f9f9;
  transition: background-color 0.3s ease;
}

.rent-item:hover {
  background-color: #f0f0f0;
}

.rent-info {
  display: flex; /* 使用 Flexbox 使订单信息和客户信息并排显示 */
  justify-content: space-between; /* 保证左右两侧信息对齐 */
  gap: 20px;
  flex-wrap: wrap; /* 当空间不足时，自动换行 */
}

.order-info,
.customer-info {
  flex: 1; /* 每部分占据相同宽度 */
  min-width: 300px; /* 设置最小宽度，防止过度缩小 */
  padding: 15px;
  background-color: #ffffff;
  border-radius: 8px;
  box-shadow: 0 2px 5px rgba(0, 0, 0, 0.1);
}

.order-info h4,
.customer-info h4 {
  margin-top: 0;
  color: #0078d4;
}

.separator {
  margin: 15px 0;
  border-top: 1px solid #ddd;
}

/* 筛选区域样式 */
.filter-container {
  display: flex;
  flex-wrap: wrap;
  align-items: center;
  gap: 15px;
  margin-bottom: 20px;
}

.filter {
  display: flex;
  align-items: center;
  gap: 8px;
  min-width: 220px; /* 限制筛选框宽度 */
}

.filter label {
  font-weight: bold;
  margin-right: 5px;
  font-size: 14px;
}

input,
select {
  padding: 8px;
  font-size: 14px;
  border: 1px solid #ddd;
  border-radius: 5px;
  width: 180px;
}

button {
  padding: 8px 14px;
  background-color: rgb(47, 119, 206);
  color: white;
  border: none;
  border-radius: 5px;
  cursor: pointer;
}

button:hover {
  background-color: darkgreen;
}
</style>
