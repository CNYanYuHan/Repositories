import axios from 'axios'

const service = axios.create({
    baseURL: 'https://www.example.com/api',
    timeout: 5000
}) 

service.interceptors.request.use(
    (config) => {
        config.headers.icode = 'input your icode here'
        return config
    },
    (error) => {
        return Promise.reject(error)
    }
);
service.interceptors.response.use(
    response => {
        const { success, message, data } = response.data;
        if (success) {
            return data
        } else {
            return Promise.reject(new Error(message) || 'Error')
        }
    }
);

export default service;