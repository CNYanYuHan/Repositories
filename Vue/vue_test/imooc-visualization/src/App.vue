<template>
    <div class="bg-[url('assets/imgs/bg.jpg')] bg-cover bg-center h-screen text-white p-5 flex overflow-hidden">
        <!-- 左 -->
        <div class="flex-1 mr-5 bg-opacity-50 bg-slate-800 p-3 flex flex-col">
        <!-- 横向柱状图 -->
         <HorizontallBar class="h-1/3 box-border pb-4" />
         <!-- 雷达图 -->
          <RadarBar class="h-1/3 box-border pb-4" />
         <!-- 关系图 -->
          <Relation class="h-1/3" />
          </div>
        <!-- 中 -->
        <div class="w-1/2 mr-5 flex flex-col">
            <!-- 数据总览图 -->
          <TotalData class="bg-opacity-50 bg-slate-800 p-3"/>
         <!-- 地图可视化 -->
          <MapChart class="bg-opacity-50 bg-slate-800 p-3 mt-4 flex-1"/>
        <!-- 右 -->
         </div>
        <div class="flex-1 bg-opacity-50 bg-slate-800 p-3 flex flex-col">
          <!-- 竖向柱状图 -->
         <VerticalBar class="h-1/3 box-border pb-4" />
         <!-- 环形图 -->
          <RingBar class="h-1/3 box-border pb-4" />
         <!-- 文档云图 -->
          <WorldCloud class="h-1/3"/>
          </div>
    </div>
</template>

<script setup>
import HorizontallBar from './components/HorizontallBar.vue';
import MapChart from './components/MapChart.vue';
import RadarBar from './components/RadarBar.vue';
import Relation from './components/Relation.vue';
import RingBar from './components/RingBar.vue';
import TotalData from './components/TotalData.vue';
import VerticalBar from './components/VerticalBar.vue';
import WorldCloud from './components/WorldCloud.vue';

import { ref } from 'vue'
import { getVisualization } from './api/visualization.js';

const data = ref(null)
const loadData = async () => {
    data.value = await getVisualization()
    console.log(data.value)
}
    loadData()

    setInterval(() => {
        loadData()
    },3000)
</script>

<style lang="scss" scoped>

</style>