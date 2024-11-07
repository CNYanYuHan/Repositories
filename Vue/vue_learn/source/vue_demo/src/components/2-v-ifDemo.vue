<template>
  <div>
    <h3>条件渲染🤔</h3>
    <div v-if="show">你能看见我吗</div>
    <div v-else>那你还是看看我吧</div>
    <div v-if="type === 'A'">A</div>
    <div v-else-if="type === 'B'">B</div>
    <div v-else-if="type === 'C'">C</div>
    <div v-else>NOT A/B/C</div>
    <div v-show="flag">你能看见我吗</div>
        <hr :style="dividerStyle" />
  </div>
</template>
<script>
export default {
  data() {
    return {
      show: false,
      type: "E",
      flag: true,
        dividerStyle: {
        width: "100%",
        borderColor: "red",
        backgroundColor: 'blue', 
        height: "3px",
      },
    };
  },
};
</script>