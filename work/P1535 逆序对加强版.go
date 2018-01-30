package main

import (
	"fmt"
)

func mergeSort() {
	var n int
	fmt.Scanf("%d", &n)
	var data [2][1000000]int
	for i := 0; i < n; i ++ {
		fmt.Scanf("%d", &data[1][i])
	}
	var leftStart, leftEnd, rightStart, rightEnd int
	var currentLevel, targetLevel int
	var position int
	var count int64
	times := 0
	for level := 1; level/2 < n; level = level << 1 {
		times += 1
		if level == 1 {
			continue
		}
		currentLevel = times % 2
		targetLevel = (currentLevel + 1) % 2
		gap := level / 2
		for position = 0; position < n; {
			// init left and right range
			leftStart = position
			leftEnd = leftStart + gap - 1
			rightStart = leftEnd + 1
			if rightStart >= n {
				break
			}
			rightEnd = rightStart + gap - 1
			if rightEnd >= n {
				rightEnd = n - 1
			}
			// merge sort
			for ; leftStart <= leftEnd && rightStart <= rightEnd; {
				if data[targetLevel][leftStart] > data[targetLevel][rightStart] {
					data[currentLevel][position] = data[targetLevel][rightStart]
					count += int64(leftEnd + 1 - leftStart)
					rightStart ++
					position ++
				} else {
					data[currentLevel][position] = data[targetLevel][leftStart]
					leftStart ++
					position ++
				}
			}
			for ; leftStart <= leftEnd; leftStart++ {
				data[currentLevel][position] = data[targetLevel][leftStart]
				position++
			}
			for ; rightStart <= rightEnd; rightStart ++ {
				data[currentLevel][position] = data[targetLevel][rightStart]
				position++
			}
		}
		for ; position < n; position ++ {
			data[currentLevel][position] = data[targetLevel][position]
		}
	}
	fmt.Printf("%d\n", count)

}

const maxNum = 1000000

type myTree [2097151]int

func insertTree(num, index, left, right int, tree *myTree) {
	(*tree)[index] += 1
	if left == right {
		return
	}
	middle := (left + right) / 2
	if num <= middle {
		insertTree(num, (index<<1)+1, left, middle, tree)
	} else {
		insertTree(num, (index<<1)+2, middle+1, right, tree)
	}
}

func queryTree(index, left, right, start, end int, tree *myTree) int64 {
	if start <= left && right <= end {
		return int64((*tree)[index])
	}
	middle := (left + right) / 2
	if start > middle {
		return queryTree((index<<1)+2, middle+1, right, start, end, tree)
	} else if end <= middle {
		return queryTree((index<<1)+1, left, middle, start, end, tree)
	} else {
		leftCount := queryTree((index<<1)+1, left, middle, start, middle, tree)
		rightCount := queryTree((index<<1)+2, middle+1, right, middle+1, end, tree)
		return leftCount + rightCount
	}
}

func segmentTree() {
	var n, num int
	fmt.Scanf("%d", &n)
	var tree myTree
	var result int64
	for i := 0; i < n; i ++ {
		fmt.Scanf("%d", &num)
		insertTree(num, 0, 0, maxNum, &tree)
		result += queryTree(0, 0, maxNum, num+1, maxNum, &tree)
	}
	fmt.Printf("%d\n", result)
}

func main() {
	//mergeSort()
	segmentTree()
}
