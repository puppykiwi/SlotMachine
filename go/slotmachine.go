package main

import "fmt"
import "reflect"

func main(){
	
	var running bool = true
	balance := getDeposit(running)

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
		fmt.Println("You are left with, ",balance,"shillings")
	}
}

func getDeposit(running bool ) int {
	
	var amount int
	for running{
		fmt.Println("How much would you like to deposit: ")
		fmt.Scanln(&amount)
		if reflect.TypeOf(amount).Name() == "int"{
			if amount > 1{
				break
				} else {
					fmt.Println("Your deposit must be greater than 0")
			}
			} else { fmt.Println("Enter a valid number")
		}

	}
	return amount
}