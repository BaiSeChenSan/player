<template>
  <div class="whr-menu">
    <div v-for="(item, index) in menus" :key="index">
      <div
        v-ripple
        class="whr-pmenu-item"
        :class="{ activeMenu: activeItem == item.url }"
        @click="clickitem(item, index)"
      >
        <div style="display: flex">
          <div style="width: 30px">
            <i :class="item.icon" style="margin-right: 20px"></i>
          </div>
          <div>
            {{ item.title }}
          </div>
          <div
            class="xiaoqiu"
            v-show="!item.isexpand && pgreen == item.url"
            :style="{ backgroundColor: pointcolor }"
          ></div>
        </div>
      </div>

      <div
        v-if="item.children"
        class="childrendiv"
        :class="{ havechildren: item.isexpand }"
      >
        <div
          v-ripple
          class="whr-sbmenu-item"
          :class="{ activesbMenu: activesbItem == sb_item.url }"
          @click="clicksbitem(sb_item, item)"
          v-for="(sb_item, sb_index) in item.children"
          :key="sb_index"
        >
          {{ sb_item.title }}
          <div
            class="xiaoqiu"
            v-show="$route.path == sb_item.url"
            :style="{ backgroundColor: pointcolor }"
          ></div>
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
      menu: [
        {
          title: "题库管理",
          url: "/index/questionlist",
          icon: "el-icon-files",
          children: [
            {
              title: "题库列表",
              url: "/index/question/questionlist",
            },
          ],
        },
        {
          title: "活动管理",
          url: "/index/activity",
          icon: "el-icon-help",
          children: [
            {
              title: "活动列表",
              url: "/index/activity/activitylist",
            },
          ],
        },
        {
          title: "系统设置",
          url: "/index/sys",
          icon: "el-icon-setting",
          children: [
            {
              title: "用户管理",
              url: "/index/sys/user",
            },
          ],
        },
      ],
      props: {
        //菜单数据必输是数组 包含 url title icon children
        menu: {
          type: Array,
          required: true,
        },
        //父级激活左边阴影颜色
        pletcolor: {
          type: String,
          default: "#856ab5",
        },
        //小球颜色
        pointcolor: {
          type: String,
          default: "#1ab3a3",
        },
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
    menus() {
      let menus = this.menu.map((item) => {
        if (item.children) {
          item.isexpand = false;
        }
        return item;
      });
      return menus;
    },
    clickitem(item, index) {
      this.menus[index].isexpand = !item.isexpand;
      this.activeItem = item.url;
      if (item.children) {
        //有子菜单，设置子元素高度
        this.activeLength = item.children.length * 49 + 20 + "px";
      }
      this.$emit("dianp", item);
      console.log("当前激活父级菜单", this.activeItem);
    },
    clicksbitem(item, pitem) {
      //点击子菜单
      this.activesbItem = item.url;
      this.activeItem = pitem.url;
      this.$emit("dianc", { item, pitem });
    },
    //父级菜单绿点位置
    pgreen() {
      let u = [];
      u = this.menus.filter((item) => {
        let xu = [];
        if (item.children.length > 0) {
          xu = item.children.filter((i) => {
            return i.url == this.$route.path;
          });
          if (xu.length > 0) {
            return true;
          } else {
            return false;
          }
        } else {
          return item.url == this.$route.path;
        }
      });
      return u[0].url;
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
