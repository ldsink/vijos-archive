package main

import (
	"fmt"
)

var data [1000000]int
var sorted [1000000]int
var count int64 = 0

func mergeSort(left, right int) {
	if left >= right {
		return
	}

	middle := (left + right) >> 1
	mergeSort(left, middle)
	mergeSort(middle+1, right)

	leftStart := left
	rightStart := middle + 1
	position := left

	for leftStart <= middle || rightStart <= right {
		if leftStart <= middle && rightStart <= right {
			if data[leftStart] > data[rightStart] {
				count += int64(middle + 1 - leftStart)
				sorted[position] = data[rightStart]
				position++
				rightStart++
			} else {
				sorted[position] = data[leftStart]
				position++
				leftStart++
			}
		} else if leftStart <= middle {
			sorted[position] = data[leftStart]
			position++
			leftStart++
		} else if rightStart <= right {
			sorted[position] = data[rightStart]
			position++
			rightStart++
		}
	}

	for i := left; i <= right; i++ {
		data[i] = sorted[i]
	}
}

func main() {
	var n int
	_, _ = fmt.Scanf("%d", &n)
	for i := 0; i < n; i++ {
		_, _ = fmt.Scanf("%d", &data[i])
	}
	mergeSort(0, n-1)
	fmt.Printf("%d\n", count)
}
