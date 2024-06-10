package main

import "fmt"

func main(){
	
	// balance := getDeposit()
	var running bool = true

	for running{
		var value string
		// fmt.Println("Your current game balnce is:", balance," shillings")
		fmt.Println("Press {ENTER} to continue  or {Q} to quit the game")
		_,err := fmt.Scanln(&value)

		if err != nil{
			fmt.Println("Error found; ",err)
			continue
		}
		
		if string(value[0]) == "Q" || string(value[0]) == "q"{
			fmt.Println("Quiting game")
			break
			// running = false
		}
		fmt.Println("now")
	}
}