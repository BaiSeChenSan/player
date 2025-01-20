import Vue from "vue";
import App from "./App.vue";
import router from "./router"; // 引入你的路由配置
Vue.config.productionTip = false;

new Vue({
  router, // 确保挂载了路由
  render: (h) => h(App),
}).$mount("#app");
