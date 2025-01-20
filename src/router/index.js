import Vue from "vue";
import VueRouter from "vue-router";
import HomeView from "../views/HomeView.vue";
import BookTest from "../views/BookTest.vue";
import VehicleManagement from "../views/VehicleManagement.vue";
import DriverManagement from "../views/DriverManagement.vue";
import OrderCenter from "../views/OrderCenter.vue";
import CarDetail from "../views/CarDetail.vue";
import RentDetail from "@/views/RentDetail.vue";
import ReturnDetail from "@/views/ReturnDetail.vue";
import addCar from "@/views/addCar.vue";
import addDriver from "@/views/addDriver.vue";
import updateDriver from "@/views/updateDriver.vue";
import MoneyManagement from "@/views/MoneyManagement.vue";
import AboutView from "@/views/AboutView.vue";
import GuestManagement from "@/views/GuestManagement.vue";
import addGuest from "@/views/addGuest.vue";
import updateGuest from "@/views/updateGuest.vue";
Vue.use(VueRouter);

const routes = [
  {
    path: "/home",
    name: "home",
    component: HomeView,
  },
  {
    path: "/VehicleManagement",
    name: "VehicleManagement",

    component: VehicleManagement,
  },
  {
    path: "/DriverManagement",
    name: "DriverManagement",

    component: DriverManagement,
  },
  {
    path: "/OrderCenter",
    name: "OrderCenter",

    component: OrderCenter,
  },
  {
    path: "/",
    name: "Login",
    component: BookTest,
  },
  {
    path: "/car/:id",
    name: "CarDetail",
    component: CarDetail,
    props: true, // 确保路由参数通过 props 传递到组件
  },
  {
    path: "/rent/:carId",
    name: "RentDetail",
    component: RentDetail,
    props: true, // 确保路由参数通过 props 传递到组件
  },
  {
    path: "/return/:carId",
    name: "ReturnDetail",
    component: ReturnDetail,
    props: true, // 确保路由参数通过 props 传递到组件
  },
  {
    path: "/addCar",
    name: "addCar",
    component: addCar,
  },

  {
    path: "/addDriver",
    name: "addDriver",
    component: addDriver,
  },

  {
    path: "/MoneyManagement",
    name: "MoneyManagement",
    component: MoneyManagement,
  },

  {
    path: "/updateDriver",
    name: "updateDriver",
    component: updateDriver,
    props: true, // 确保路由参数通过 props 传递到组件
  },
  {
    path: "/AboutView",
    name: "AboutView",
    component: AboutView,
  },

  {
    path: "/GuestManagement",
    name: "GuestManagement",
    component: GuestManagement,
  },

  {
    path: "/addGuest",
    name: "addGuest",
    component: addGuest,
  },
  {
    path: "/updateGuest",
    name: "updateGuest",
    component: updateGuest,
  },
];

const router = new VueRouter({
  routes,
});

export default router;
