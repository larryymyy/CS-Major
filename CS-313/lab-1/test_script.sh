#!/bin/bash
echo "********************************************************************************"
echo "* Running Test 1/5: Compile                                                    *"

# Test to see if all files compile

javac $1/*.java
if [ $? != 0 ]; then
	echo Failed to compile.
	echo Estimated score \for lab 1: 0/50
	echo "********************************************************************************"
else
	echo Passed
	echo "********************************************************************************"
	echo "* Running Test 2/5: Data Structure Implementation                              *"
	echo "* Part a) Execution                                                            *"
	
	# Test Time Complexity of inserts
	start=$SECONDS
	java -cp $1 TestContents < /home/users/smergend/public/cs313/lab1/dsInputI.txt > $1/dsOutputI.txt
	FI=$?
	durationI=$(( SECONDS - start ))
	
	# Test Time Complexity of removes
	start=$SECONDS
	java -cp $1 TestContents < /home/users/smergend/public/cs313/lab1/dsInputR.txt > $1/dsOutputR.txt
	FR=$?
	durationR=$(( SECONDS - start ))
	
	# Check to see if TestContents ran correctly
	if [ $FI != 0 -o $FR != 0 ]; then
		echo Failed to execute TestContents.java correctly.
		echo Your \file must be \named TestContents.java
		echo Estimated score \for lab 1: 5/50
		echo "********************************************************************************"
	else
		echo Passed
		echo "* Part b) Printing                                                             *"
		# Check to see if I test printed enough
		A=$(wc -l < $1/dsOutputI.txt)
		B=$(wc -l < /home/users/smergend/public/cs313/lab1/dsOutputI.txt)
		# Check to see if P test printed enough
		C=$(wc -l < $1/dsOutputR.txt)
		D=$(wc -l < /home/users/smergend/public/cs313/lab1/dsOutputR.txt)		
		if [ $A != $B -o $C != $D ]; then
			echo Failed to print out Stack and Queue correctly.
			echo Estimated score \for lab 1: 7.5/50
			echo "********************************************************************************"
		else
			echo Passed	
			echo "********************************************************************************"
			echo "* Running Test 3/5: Palindrome Tests                                           *"
			echo "* Part a) Execution                                                            *"
			start=$SECONDS
			java -cp $1 lab1  < /home/users/smergend/public/cs313/lab1/input.txt > $1/output.txt
			FP=$?
			durationP=$(( SECONDS - start ))
			
			# Test if lab1 ran correctly
			if [ $FP != 0 ]; then
				echo Failed to execute lab1.java correctly.
				echo Your \file must be \named lab1.java.
				echo Estimated score \for lab 1: 12.5/50
				echo "********************************************************************************"
			else
				echo Passed
				echo "* Part b) Printing                                                             *"
				A=$(wc -l < $1/output.txt)
				B=$(wc -l < /home/users/smergend/public/cs313/lab1/output.txt)
				
				# Test if lab1 printed correctly		
				if [ $A != $B ]; then
					echo Failed to print correctly.
					echo Did not print out a correct number of Palindrome results.
					echo Estimated score \for lab 1: 15/50
					echo "********************************************************************************"
				else
					echo Passed
					echo "********************************************************************************"
					echo "* Running Test 4/5: Time Complexities                                          *"
					if [ $durationI -gt 5 ]; then
						echo "Failed to run Stack and Queue insert functionality in O(1)"
						echo Estimated score \for lab 1: 20/50
						echo "********************************************************************************"
					else 
						if [ $durationR -gt 5 ]; then
							echo "Failed to run Stack and Queue remove functionality in O(1)"
							echo Estimated score \for lab 1: 25/50
							echo "********************************************************************************"
						else
							if [ $durationP -gt 5 ]; then
								echo "Failed to run Palindrome functionality in O(n)"
								echo Estimated score \for lab 1: 30/50
								echo "********************************************************************************"
							else
								echo Passed
								echo "********************************************************************************"
								echo "* Running Test 5/5: Correctness                                                *"
								
								# Insert Test (4points)
								X1=$(diff -w -U 0 $1/dsOutputI.txt /home/users/smergend/public/cs313/lab1/dsOutputI.txt | grep -v ^@ | tail -n +3 | wc -l)
								Z1=$[$X1/2]
								
								if [ $Z1 -ne 0 ]; then
									echo Insert was implemented incorrectly \in either the Stack or the Queue.
									Z1=1
								else
									echo Insert was implemented correctly in both the Stack and the Queue.
								fi
								
								# Remove Test (4points)
								X2=$(diff -w -U 0 $1/dsOutputR.txt /home/users/smergend/public/cs313/lab1/dsOutputR.txt | grep -v ^@ | tail -n +3 | wc -l)
								Z2=$[$X2/2]
								
								if [ $Z2 -ne 0 ]; then
									echo Remove was implemented incorrectly \in either the Stack or the Queue.
									Z2=1
								else
									echo Remove was implemented correctly \in both the Stack and the Queue.
								fi
					
								# Palindrome Test (12points)
								X3=$(diff -w -U 0 $1/output.txt /home/users/smergend/public/cs313/lab1/output.txt | grep -v ^@ | tail -n +3 | wc -l)
								Z3=$[$X3/2]
						
								Y1=$[4*$Z1 + 4*$Z2 + ($Z3)/2]
								Y2=$[50-$Y1]
								
								echo There were $Z3 incorrect Palindrome identifications.
								echo Estimated score \for lab 1 before Extra Credit: $Y2/50
								echo "********************************************************************************"	
								echo "* Running Test 6/5: Extra Credit                                               *"
								java -cp $1 EC  < /home/users/smergend/public/cs313/lab1/inputEC.txt > $1/outputEC.txt
								
								# EC Test (4points)
								X4=$(diff -w -U 0 $1/outputEC.txt /home/users/smergend/public/cs313/lab1/outputEC.txt | grep -v ^@ | tail -n +3 | wc -l)
								Z4=$[$X4/2]
								
								if [ $Z4 -ne 0 ]; then
									echo Extra Credit failed. 
									Y3=$Y2
								else
									echo Passed
									Y3=[$Y2+10]
								fi
								
								echo Estimated final score \for lab 1: $Y3/50
								echo "********************************************************************************"	
							fi
						fi
					fi	
				fi
			fi
		fi
	fi
fi
