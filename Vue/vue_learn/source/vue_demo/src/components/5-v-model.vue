
<template>
  <div>
    <h3>表单输入</h3>
    <div class="hello">
      用户名：<input type="text" v-model.lazy="username" /> 密码：<input
        type="text"
        v-model.trim="password"
      />
      <!-- v-model 指令将数据双向绑定到输入框和 data 中的 username 变量 -->
      <p>用户信息：[{{ username }} | {{ password }}]</p>
      <button @click="clickPrintUserInformation">console输出用户名</button>
    </div>
    <hr :style="dividerStyle" />
  </div>
</template>

<script>
export default {
  name: "helloWorld",
  data() {
    return {
      username: "",
      password: "",
      dividerStyle: {
        width: "100%",
        borderColor: "black",
        backgroundColor: "pink",
        height: "3px",
      },
    };
  },
  methods: {
    clickPrintUserInformation() {
      console.log(`Username: ${this.username}
Password: ${this.password}`);
    },
    // 反引号（`）来定义模板字符串
    // ${this.username} 和 ${this.password} 是占位符，它们会被 this.username 和 this.password 的实际值所替换
  },
};
</script>