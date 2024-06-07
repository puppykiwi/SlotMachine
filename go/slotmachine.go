package main

import "fmt"

func main(){
	
	// balance := getDeposit()
	var running bool = true

	for running{
		
		// fmt.Println("Your current game balnce is:", balance," shillings")
		fmt.Println("Press {ENTER} to continue  or {Q} to quit the game")
		value,err := fmt.Scan()
		
		if err != nil{
			fmt.Println("error")
		}
		fmt.Println(value)
	}
}