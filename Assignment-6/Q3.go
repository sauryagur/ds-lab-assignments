package main

import "fmt"

type DoublyLinkedList struct {
	Value rune
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

func (dll *DLL) InsertFront(val rune) {
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

func (dll *DLL) InsertEnd(val rune) {
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
		fmt.Printf("%c ", curr.Value)
		curr = curr.Next
	}
	fmt.Println()
}

func (dll *DLL) DisplayBackward() {
	curr := dll.Tail
	for curr != nil {
		fmt.Printf("%c ", curr.Value)
		curr = curr.Prev
	}
	fmt.Println()
}

// ----- custom methods idhar se hain -----

func (dll *DLL) isPalindrome() bool {
	leftie := dll.Head
	rightie := dll.Tail
	for leftie != nil && rightie != nil {
		if leftie.Value != rightie.Value {
			return false
		}
		leftie = leftie.Next
		rightie = rightie.Prev
	}
	return true
}

func main() {
	dll := CreateDLL()
	dll.InsertFront('L')
	dll.InsertFront('E')
	dll.InsertFront('R')
	dll.InsertFront('R')
	dll.InsertFront('E')
	dll.InsertFront('L')
	dll.DisplayForward()
	dll.DisplayBackward()
	fmt.Println(dll.isPalindrome())	
}

