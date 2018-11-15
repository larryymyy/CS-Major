#!/bin/bash

echo "********************************************************************************"
echo "* Running Test 1/7: Compile                                                    *"

# Test to see if all files compile
javac $1/*.java
if [ $? != 0 ]; then
	echo Failed to compile.
	echo Estimated score \for lab 3: 0/50
	echo "********************************************************************************"
else
	echo Passed
	echo "********************************************************************************"
	echo "* Running Test 2/7: Data Structure Implementation - Insert                     *"
	echo "* Part a) Execution                                                            *"
	
	# Test Time Complexity of inserts
	start=$SECONDS
	java -cp $1 lab3 < ./data/insertTest1.txt > $1/outputInsert1.txt
	I1=$?
	durI1=$(( SECONDS - start ))
	
	start=$SECONDS
	java -cp $1 lab3 < ./data/insertTest2.txt > $1/outputInsert2.txt
	I2=$?
	durI2=$(( SECONDS - start ))
	
	# Check to see if insert ran correctly
	if [ $I1 != 0 -o $I2 != 0 ]; then
		echo Failed to execute insert commands correctly.
		echo Your \file must be \named lab3.java
		echo Estimated score \for lab 3: 5/50
		echo "********************************************************************************"
	else
		echo Passed
		echo "* Part b) Printing                                                             *"
		
		# Check to see if test 1 test printed enough
		A=$(wc -l < $1/outputInsert1.txt)
		B=$(wc -l < ./data/outputInsert1.txt)
		
		# Check to see if test 2 printed enough
		C=$(wc -l < $1/outputInsert2.txt)
		D=$(wc -l < ./data/outputInsert2.txt)	
			
		if [ $A != $B -o $C != $D ]; then
			echo Failed to print out insert commands correctly.
			echo Estimated score \for lab 3: 7.5/50
			echo "********************************************************************************"
		else
			echo Passed	
			echo "********************************************************************************"
			echo "* Part c) Correctness                                                          *"
			
			# Compare the outputs
			X1=$(diff -w -U 0 $1/outputInsert1.txt ./data/outputInsert1.txt | grep -v ^@ | tail -n +3 | wc -l)
			Z1=$[$X1/2]
			
			if [ $Z1 -ne 0 ]; then
				echo Failed the first insert test. 
				echo Estimated score \for lab 1: 10/50
			else			
				X2=$(diff -w -U 0 $1/outputInsert2.txt ./data/outputInsert2.txt | grep -v ^@ | tail -n +3 | wc -l)
				Z2=$[$X2/2]
				
				if [ $Z2 -ne 0 ]; then
					echo Failed the second insert test. 
					echo Estimated score \for lab 1: 12.5/50
				else
					echo Passed
					echo "********************************************************************************"
					echo "* Running Test 3/7: Data Structure Implementation - Maximum                    *"
					echo "* Part a) Execution                                                            *"
					
					# Test Time Complexity of maximum
					start=$SECONDS
					java -cp $1 lab3 < ./data/maximumTest.txt > $1/outputM.txt
					M1=$?
					durM1=$(( SECONDS - start ))
					
					# Check to see if max ran correctly
					if [ $M1 != 0 ]; then
						echo Failed to execute maximum commands correctly.
						echo Your \file must be \named lab3.java
						echo Estimated score \for lab 3: 15/50
						echo "********************************************************************************"
					else
						echo Passed
						echo "* Part b) Printing                                                             *"
						
						# Check to see if test 1 test printed enough
						A=$(wc -l < $1/outputM.txt)
						B=$(wc -l < ./data/outputM.txt)
			
						if [ $A != $B ]; then
							echo Failed to print out maximum commands correctly.
							echo Estimated score \for lab 3: 17.5/50
							echo "********************************************************************************"
						else
							echo Passed	
							echo "********************************************************************************"
							echo "* Part c) Correctness                                                          *"
							
							# Compare the outputs
							X1=$(diff -w -U 0 $1/outputM.txt ./data/outputM.txt | grep -v ^@ | tail -n +3 | wc -l)
							Z1=$[$X1/2]
			
							if [ $Z1 -ne 0 ]; then
								echo Failed the maximum test. 
								echo Estimated score \for lab 3: 20/50
							else		
								echo Passed
								echo "********************************************************************************"	
								echo "* Running Test 4/7: Data Structure Implementation - extractMax                 *"
								echo "* Part a) Execution                                                            *"
								
								# Test Time Complexity of extractMax
								start=$SECONDS
								java -cp $1 lab3 < ./data/extractMaxTest.txt > $1/outputEM.txt
								EM1=$?
								durEM1=$(( SECONDS - start ))
						
								# Check to see if max ran correctly
								if [ $EM1 != 0 ]; then
									echo Failed to execute extractMax commands correctly.
									echo Your \file must be \named lab3.java
									echo Estimated score \for lab 3: 22.5/50
									echo "********************************************************************************"
								else
									echo Passed
									echo "* Part b) Printing                                                             *"
							
									# Check to see if test 1 test printed enough
									A=$(wc -l < $1/outputEM.txt)
									B=$(wc -l < ./data/outputEM.txt)
			
									if [ $A != $B ]; then
										echo Failed to print out extractMax commands correctly.
										echo Estimated score \for lab 3: 25/50
										echo "********************************************************************************"
									else
										echo Passed	
										echo "********************************************************************************"
										echo "* Part c) Correctness                                                          *"
							
										# Compare the outputs
										X1=$(diff -w -U 0 $1/outputM.txt ./data/outputM.txt | grep -v ^@ | tail -n +3 | wc -l)
										Z1=$[$X1/2]
				
										if [ $Z1 -ne 0 ]; then
											echo Failed the extractMax test. 
											echo Estimated score \for lab 3: 27.5/50
										else		
											echo Passed
											echo "********************************************************************************"
											echo "* Running Test 5/7: Data Structure Implementation - isEmpty                    *"
											echo "* Part a) Execution                                                            *"
								
											# Test Time Complexity of isEmpty
											start=$SECONDS
											java -cp $1 lab3 < ./data/isEmptyTest.txt > $1/outputIE.txt
											IE=$?
											durIE=$(( SECONDS - start ))
						
											# Check to see if max ran correctly
											if [ $IE != 0 ]; then
												echo Failed to execute isEmpty commands correctly.
												echo Your \file must be \named lab3.java
												echo Estimated score \for lab 3: 30/50
												echo "********************************************************************************"
											else
												echo Passed
												echo "* Part b) Printing                                                             *"
							
												# Check to see if test 1 test printed enough
												A=$(wc -l < $1/outputIE.txt)
												B=$(wc -l < ./data/outputIE.txt)
			
												if [ $A != $B ]; then
													echo Failed to print out isEmpty commands correctly.
													echo Estimated score \for lab 3: 32.5/50
													echo "********************************************************************************"
												else
													echo Passed	
													echo "********************************************************************************"
													echo "* Part c) Correctness                                                          *"
							
													# Compare the outputs
													X1=$(diff -w -U 0 $1/outputIE.txt ./data/outputIE.txt | grep -v ^@ | tail -n +3 | wc -l)
													Z1=$[$X1/2]
				
													if [ $Z1 -ne 0 ]; then
														echo Failed the isEmpty test. 
														echo Estimated score \for lab 3: 35/50
													else		
														echo Passed
														echo "********************************************************************************"
														echo "* Running Test 6/7: Data Structure Implementation - Combination of Commands    *"
														echo "* Part a) Execution                                                            *"
								
														# Test Time Complexity of test1
														start=$SECONDS
														java -cp $1 lab3 < ./data/inputTest1.txt > $1/outputTest1.txt
														O1=$?
														durO1=$(( SECONDS - start ))
														
														# Test Time Complexity of test2
														start=$SECONDS
														java -cp $1 lab3 < ./data/inputTest2.txt > $1/outputTest2.txt
														O2=$?
														durO2=$(( SECONDS - start ))
														
						
														# Check to see if tests ran correctly
														if [ $O1 != 0 -o $O2 != 0 ]; then
															echo Failed to execute combination commands correctly.
															echo Your \file must be \named lab3.java
															echo Estimated score \for lab 3: 37.5/50
															echo "********************************************************************************"
														else
															echo Passed
															echo "* Part b) Printing                                                             *"
							
															# Check to see if test 1 test printed enough
															A=$(wc -l < $1/outputTest1.txt)
															B=$(wc -l < ./data/outputTest1.txt)
															
															# Check to see if test 2 test printed enough
															C=$(wc -l < $1/outputTest2.txt)
															D=$(wc -l < ./data/outputTest2.txt)
			
															if [ $A != $B -o $C != $D ]; then
																echo Failed to print out combination commands correctly.
																echo Estimated score \for lab 3: 40/50
																echo "********************************************************************************"
															else
																echo Passed	
																echo "********************************************************************************"
																echo "* Part c) Correctness                                                          *"
							
																# Compare the outputs
																X1=$(diff -w -U 0 $1/outputTest1.txt ./data/outputTest1.txt | grep -v ^@ | tail -n +3 | wc -l)
																Z1=$[$X1/2]
																
																# Compare the outputs
																X2=$(diff -w -U 0 $1/outputTest1.txt ./data/outputTest1.txt | grep -v ^@ | tail -n +3 | wc -l)
																Z2=$[$X2/2]
				
																if [ $Z1 -ne 0 -o $Z2 -ne 0 ]; then
																	echo Failed the combination test. 
																	echo Estimated score \for lab 3: 42.5/50
																else		
																	echo Passed
																	echo "********************************************************************************"
																	echo "* Running Test 7/7: Data Structure Implementation - Time Complexity            *"
								
																	# Test Time Complexity compares
																	if [ $durO1 -gt 1 -o $durO2 -gt 1 ]; then
																		echo Failed Time Complexity Test
																		Y=45
																		echo Estimated score \for lab 3 before Extra Credit: 45/50
																	else
																		echo Passed
																		Y=50
																		echo Estimated score \for lab 3 before Extra Credit: 50/50
																	fi
																	echo "********************************************************************************"
																	echo "* Running Test 8/7: Extra Credit                                               *"
																	java -cp $1 lab3 < ./data/EC.txt > $1/outputEC.txt
																	EC=$?
																	
																	# Compare the sizes of outputs
																	A=$(wc -l < $1/outputEC.txt)
																	B=$(wc -l < ./data/outputEC.txt)
																	
																	# Compare the outputs
																	XE=$(diff -w -U 0 $1/outputEC.txt ./data/outputEC.txt | grep -v ^@ | tail -n +3 | wc -l)
																	ZE=$[$XE/2]
															
				
																	if [ $ZE -ne 0 -o $EC != 0 -o $A != $B ]; then
																		echo Failed the Extra Credit test. 
																		echo Estimated score \for lab 3: $Y/50
																	else		
																		echo Passed
																		echo Estimated score \for lab 3: [$Y+10]/50
																	fi
																fi
															fi
														fi
													fi
												fi
											fi
										fi
									fi
								fi
							fi
						fi
					fi
				fi
			fi
		fi
	fi
fi
				
								

	
	
	
	
