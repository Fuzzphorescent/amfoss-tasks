package main

import (

    "syscall/js"
)

var Count = 0

func main() {
	
	registerCallbacks()
	select {}
}

func increment(this js.Value, i []js.Value) interface{} {
	Count++
	doc := js.Global().Get("document")
    body := doc.Call("getElementById", "int")
	body.Set("innerHTML", Count)
	return nil
}

func decrement(this js.Value, i []js.Value) interface{} {
	Count--
	doc := js.Global().Get("document")
    body := doc.Call("getElementById", "int")
	body.Set("innerHTML", Count)
	return nil
}

func reset(this js.Value, i []js.Value) interface{} {
	Count = 0
	doc := js.Global().Get("document")
    body := doc.Call("getElementById", "int")
	body.Set("innerHTML", Count)
	return nil
}

func registerCallbacks() {
    js.Global().Set("inc", js.FuncOf(increment))
    js.Global().Set("dec", js.FuncOf(decrement))
	js.Global().Set("reset", js.FuncOf(reset))

}