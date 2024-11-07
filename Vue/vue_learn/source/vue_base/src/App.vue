
<template>
<h3>模板语法</h3>
<p>{{ msg }}</p>
<p>{{ hello }}</p>
<p>{{ number + 1 }}</p>
<p>{{ ok? 'Yes' : 'No' }}</p>
<p>{{message.split("").reverse().join("")}}</p>
<p>{{ rawHtml }}</p>
<p v-html = "rawHtml"> </p>
</template>

<script>
  export default {
    data() {
      return {
        msg: "神奇的Vue",
        hello: "hello world",
        number: 10,
        ok: true,
        message: "大家好",
        rawHtml:"<a href='http://www.baidu.com'>百度</a>"
      }
    }
}
</script>