package main

import "fmt"

func twoSum(nums []int, target int) []int {
    m := make(map[int]int)
    for i := 0; i < len(nums); i++ {
        sub := target - nums[i]
        if _, ok := m[sub]; ok {
            return []int{m[sub], i}
        }
    }
    return nil
}

func main(){
    var nums = [4]int{2,7,11,15}
    var tag = twoSum(nums,9)
    fmt.Println(tag[0],tag[i])
}

