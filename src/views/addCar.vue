<template>
  <div class="add-car-container">
    <h2>添加车辆</h2>
    <form @submit.prevent="submitForm">
      <div class="form-group">
        <label for="CNo">车牌号:</label>
        <input type="text" id="CNo" v-model="newCar.CNo" required />
      </div>

      <div class="form-group">
        <label for="CType">车辆类型:</label>
        <select id="CType" v-model="newCar.CType" required>
          <option value="A级车">A级车</option>
          <option value="B级车">B级车</option>
          <option value="SUV">SUV</option>
          <option value="MPV">MPV</option>
          <option value="中型大巴">中型大巴</option>
        </select>
      </div>

      <div class="form-group">
        <label for="CPrice">购入价格:</label>
        <input type="number" id="CPrice" v-model="newCar.CPrice" required />
      </div>

      <div class="form-group">
        <label for="CBuyDate">购入日期:</label>
        <input type="date" id="CBuyDate" v-model="newCar.CBuyDate" required />
      </div>

      <div class="form-group">
        <label for="CFixDate">上次维修日期:</label>
        <input type="date" id="CFixDate" v-model="newCar.CFixDate" />
      </div>

      <div class="form-group">
        <label for="CDistance">行驶公里数:</label>
        <input
          type="number"
          id="CDistance"
          v-model="newCar.CDistance"
          required
        />
      </div>

      <div class="form-group">
        <label for="CUnit">租车价格(¥/天):</label>
        <input type="number" id="CUnit" v-model="newCar.CUnit" required />
      </div>

      <div class="form-group">
        <label for="CBrand">品牌:</label>
        <input type="text" id="CBrand" v-model="newCar.CBrand" required />
      </div>

      <div class="form-group">
        <label for="CModel">型号:</label>
        <input type="text" id="CModel" v-model="newCar.CModel" required />
      </div>

      <button type="submit">提交</button>
    </form>
  </div>
</template>

<script>
import axios from "axios";

export default {
  data() {
    return {
      newCar: {
        CNo: "",
        CType: "",
        CPrice: 0,
        CBuyDate: "",
        CFixDate: "",
        CDistance: 0,
        CUnit: 0,
        CBrand: "",
        CModel: "",
        CStatus: "0",
      },
    };
  },
  methods: {
    submitForm() {
       axios.post(
        "http://localhost:8081/car/addCar",
        this.newCar,
        {
          withCredentials: true,
        }
      );
      this.$router.push("/VehicleManagement");
      alert("添加车辆成功");
    },
  },
};
</script>

<style scoped>
.add-car-container {
  width: 400px;
  margin: 0 auto;
  padding: 20px;
  border: 1px solid #ddd;
  border-radius: 8px;
  background-color: #f9f9f9;
}

h2 {
  text-align: center;
  margin-bottom: 20px;
}

.form-group {
  margin-bottom: 15px;
}

label {
  display: block;
  margin-bottom: 5px;
}

input,
select {
  width: 100%;
  padding: 8px;
  font-size: 14px;
  border-radius: 4px;
  border: 1px solid #ccc;
}

button {
  width: 100%;
  padding: 10px;
  background-color: #4caf50;
  color: white;
  font-size: 16px;
  border: none;
  border-radius: 5px;
  cursor: pointer;
}

button:hover {
  background-color: #45a049;
}
</style>
