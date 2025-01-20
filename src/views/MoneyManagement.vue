<template>
  <div class="container">
    <!-- 背景部分 -->
    <div class="background"></div>

    <!-- 页面内容 -->
    <div class="content">
      <h2>财务信息</h2>
      <div class="balance">
        <div class="income">
          <h3>出租费用收入</h3>
          <p>{{ income ? `￥${income}` : "加载中..." }}</p>
        </div>
        <div class="expense">
          <h3>购车费用支出</h3>
          <p>{{ expense ? `￥${expense}` : "加载中..." }}</p>
        </div>
      </div>
    </div>
  </div>
</template>

<script>
import axios from "axios";

export default {
  data() {
    return {
      income: null, // 收入
      expense: null, // 支出
    };
  },
  mounted() {
    this.fetchFinancialData();
  },
  methods: {
    // 获取收入和支出数据
    async fetchFinancialData() {
      try {
        // 获取收入
        const incomeResponse = await axios.get(
          "http://localhost:8081/rent/getTotalMoney"
        );
        this.income = incomeResponse.data;

        // 获取支出
        const expenseResponse = await axios.get(
          "http://localhost:8081/car/getBuyMoney"
        );
        this.expense = expenseResponse.data;
      } catch (error) {
        console.error("数据获取失败", error);
      }
    },
  },
};
</script>

<style scoped>
.container {
  font-family: "Arial", sans-serif;
  height: 100vh;
  display: flex;
  justify-content: center;
  align-items: center;
  flex-direction: column;
}

.background {
  position: absolute;
  top: 0;
  left: 0;
  width: 100%;
  height: 100%;
  background-image: url("https://tse1-mm.cn.bing.net/th/id/OIP-C.1649rQYRwAfmShfU-zmZkwHaEK?rs=1&pid=ImgDetMain"); /* 背景图片 */
  background-size: cover;
  background-position: center;
  opacity: 0.5; /* 可调透明度 */
}
.money-text {
  font-size: 120px;
  font-weight: bold;
  color: gold;
  opacity: 0.8;
}

.content {
  z-index: 10;
  text-align: center;
  background-color: white;
  padding: 30px;
  border-radius: 10px;
  box-shadow: 0 0 15px rgba(0, 0, 0, 0.1);
  width: 100%;
  max-width: 400px;
  opacity: 0.7;
}

.balance {
  margin-top: 20px;
}

.income,
.expense {
  margin-bottom: 20px;
}

h2 {
  color: #333;
}

h3 {
  color: #333;
}

p {
  font-size: 18px;
  color: #0078d4;
}
</style>
