// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"

void UMyBlueprintFunctionLibrary::CalculatePrimeNumbers(int NumToCalculate, TArray<int>& OutPrimeNumbers)
{
	check(NumToCalculate >= 2);
	OutPrimeNumbers.Empty();
	OutPrimeNumbers.Add(2);
	OutPrimeNumbers.Add(3);

	while (OutPrimeNumbers.Num() < NumToCalculate)
	{
		int NumToTest = OutPrimeNumbers.Last();
		bool IsPrime = false;
		while (!IsPrime)
		{
			IsPrime = true;
			NumToTest++;
			for (int Divisor = 2; Divisor < NumToTest; ++Divisor)
			{
				if (NumToTest % Divisor == 0)
				{
					IsPrime = false;
					break;
				}
			}
		}
		OutPrimeNumbers.Add(NumToTest);
	}
}
