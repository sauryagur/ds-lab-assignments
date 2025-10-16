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

func main() {
	dll := CreateDLL()
	dll.InsertFront(10)
	dll.InsertEnd(20)
	dll.InsertFront(5)
	dll.DisplayForward()
	dll.DisplayBackward()
}
