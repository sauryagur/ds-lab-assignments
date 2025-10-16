package main

import "fmt"

type DoublyLinkedList struct {
	Value int
	Next  *DoublyLinkedList
	Prev  *DoublyLinkedList
}

type DLL struct {
	Head *DoublyLinkedList
	Tail *DoublyLinkedList
}

func CreateDLL() *DLL {
	return &DLL{nil, nil}
}

func (dll *DLL) InsertFront(val int) {
	node := &DoublyLinkedList{Value: val}
	if dll.Head == nil {
		dll.Head = node
		dll.Tail = node
	} else {
		node.Next = dll.Head
		dll.Head.Prev = node
		dll.Head = node
	}
}

func (dll *DLL) InsertEnd(val int) {
	node := &DoublyLinkedList{Value: val}
	if dll.Tail == nil {
		dll.Head = node
		dll.Tail = node
	} else {
		dll.Tail.Next = node
		node.Prev = dll.Tail
		dll.Tail = node
	}
}

func (dll *DLL) DisplayForward() {
	curr := dll.Head
	for curr != nil {
		fmt.Print(curr.Value, " ")
		curr = curr.Next
	}
	fmt.Println()
}

func (dll *DLL) DisplayBackward() {
	curr := dll.Tail
	for curr != nil {
		fmt.Print(curr.Value, " ")
		curr = curr.Prev
	}
	fmt.Println()
}

// ----- custom methods idhar se hain -----

func (dll *DLL) Q2() {
	curr := dll.Head
	firstElement := curr.Value
	for curr != nil {
		fmt.Print(curr.Value, " ")
		curr = curr.Next
	}
	fmt.Print(firstElement)
	fmt.Println()
}

func (dll *DLL) Q2Legit() {
	curr := dll.Head
	for curr.Next != nil {
		fmt.Print(curr.Value, " ")
		curr = curr.Next
	}
	fmt.Print(curr.Value, " ")
	for curr.Prev != nil {
		curr = curr.Prev
	}
	fmt.Print(curr.Value, " ")
	fmt.Println()
}

func main() {
	dll := CreateDLL()
	dll.InsertFront(10)
	dll.InsertEnd(20)
	dll.InsertFront(5)
	dll.Q2()
	dll.Q2Legit()
}

