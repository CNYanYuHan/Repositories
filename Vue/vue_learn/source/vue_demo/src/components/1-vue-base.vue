
<template>
  <div>
    <h1 :style="{textAlign: 'center' }">Vue学习 (⓿_⓿)</h1>
    <h3>模板语法🙂</h3>
    <div :id="yyhId" :class="yyhClass" :title="yyhTitle">测试</div>
    <button :disabled="isButtonDisabled">坏掉的的按钮</button>
    <div v-bind="objectOfAttrs">测试</div>

    <hr :style="dividerStyle" />
  </div>
</template>

<script>
export default {
  data() {
    return {
      yyhId: "appId",
      yyhClass: "appClass",
      yyhTitle: undefined,
      isButtonDisabled: false,
      objectOfAttrs: {
        class: "appClass",
        id: "appId",
      },
        dividerStyle: {
        width: '100%',
        borderColor: 'blue',
        backgroundColor: 'red', 
        height: '3px',
    },
  };
},
};
</script>

<style>
.appClass {
  color: red;
  font-size: 30px;
}
</style>