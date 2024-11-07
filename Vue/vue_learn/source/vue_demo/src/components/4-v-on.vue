<template>
  <div>
    <h3>事件处理</h3>
    <p :style="{ color: messageColor }">{{ message }}</p>

    <button @click="clickHandle">😗隐瞒好消息</button>
    <button @click="resetHandle">😘发布好消息</button>
    <button @click="counter += 1">🪵🦈电子木鱼（功德 + {{ counter }}）</button>
    <!-- v-on:简写为@ -->
    <ul>
    <p>👇点击邀请嘉宾：(console中会打印出被点击的名字)</p>
      <li
        @click="clickItemHandle(name)"
        v-for="(name, index) in names"
        :key="index"
      >
        {{ name }}
      </li>
    </ul>

    <hr :style="dividerStyle" />
  </div>
</template>

<script>
export default {
  data() {
    return {
      counter: 0,
      message: "🤩好消息！好消息！！",
      names: ["Rossy", "Edward", "Frank"],
      messageColor: "red",
      dividerStyle: {
        width: "100%",
        borderColor: "pink",
        backgroundColor: "green",
        height: "3px",
      },
    };
  },
  methods: {
    clickHandle(event) {
      console.log("哈哈哈~");
      //在事件中，读取data中的属性，是需要通过this来实现的。
      this.message = "😒你撤回了一条消息~";
      this.messageColor = "blue";
      //'event' 是原生DOM事件对象，包含了事件的所有信息。
      console.log(event);
      event.target.innerHTML = "😅隐瞒好消息";
    },
    resetHandle(event) {
      this.message = "🩷我要结婚了！";
      this.messageColor = "red";
      console.log(event);
      event.target.innerHTML = "😍发布好消息";
    },
    clickItemHandle(name) {
      console.log(name);
    },
  },
};
</script>
