<template>
  <div>
    <h3>列表渲染😅</h3>
    <ul>
      <li v-for="item in newslist" :key="item.id">
        {{ item.title }}
      </li>
    </ul>

    <p v-for="(item, index) in names" :key="index">{{ item }}-{{ index }}</p>

    <div v-for="item in result" :key="item.name">
      <p>{{ item.name }}-{{ item.work }}-{{ item.age }}</p>
    </div>

    <p v-for="(value, name, index) in userInfos" :key="index">
      {{ name }}:{{ value }}
    </p>
    <hr :style="dividerStyle" />
  </div>
</template>

<script>
export default {
  data() {
    return {
      newslist:[
        {id:1001,
          title:"今日新闻1"
        },
        {id:1002,
          title:"今日新闻2"
        },
        {id:1003,
          title:"今日新闻3"
        },
      ],
      names: ["程序员", "厨师", "老师"],
      result: [
        { name: "Yan", work: "程序员", age: "25岁" },
        { name: "Tom", work: "厨师", age: "30岁" },
        { name: "Jerry", work: "老师", age: "28岁" },
      ],
      userInfos: {
        姓名: "张三",
        年龄: 30,
      },
      dividerStyle: {
        width: "100%",
        borderColor: "pink",
        backgroundColor: "yellow",
        height: "3px",
      },
    };
  },
};
</script>
