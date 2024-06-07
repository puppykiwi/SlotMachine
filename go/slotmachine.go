package main

import "fmt"

func main(){
	
	// balance := getDeposit()
	var running bool = true

	for running{
		
		// fmt.Println("Your current game balnce is:", balance," shillings")
		fmt.Println("Press {ENTER} to continue  or {Q} to quit the game")
		value,err := fmt.Scanln()
		value = string(value)
		
		if err != nil{
			fmt.Println("Error found; ")
			continue
		}
		
		if value[0] == "\n"{
			fmt.Println("Continuing game")
		}
	}
}