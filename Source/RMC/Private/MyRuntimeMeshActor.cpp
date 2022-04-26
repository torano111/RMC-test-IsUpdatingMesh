// Fill out your copyright notice in the Description page of Project Settings.

#include "MyRuntimeMeshActor.h"
#include "MyRuntimeMeshProvider.h"

AMyRuntimeMeshActor::AMyRuntimeMeshActor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, BoxRadius(50.f)
	, NumPrimeNumbersToCalculate(100)
{
	SetMobility(EComponentMobility::Movable);
}

void AMyRuntimeMeshActor::InitializeRMC()
{
	if (MyRMP == nullptr)
	{
		MyRMP = NewObject<UMyRuntimeMeshProvider>(this, TEXT("MyRMP"));
		UpdateRMPProperties();
		GetRuntimeMeshComponent()->Initialize(MyRMP);
	}
}

void AMyRuntimeMeshActor::UpdateRMC()
{
	if (MyRMP)
	{
		UpdateRMPProperties();
		MyRMP->MarkAllLODsDirty();
	}
}

void AMyRuntimeMeshActor::GetPrimeNumbers(TArray<int>& OutPrimeNumbers)
{
	OutPrimeNumbers.Empty();
	if (MyRMP)
	{
		MyRMP->GetPrimeNumbers(OutPrimeNumbers);
	}
}

void AMyRuntimeMeshActor::UpdateRMPProperties()
{
	if (MyRMP)
	{
		MyRMP->SetBoxMaterial(BoxMaterial);
		MyRMP->SetBoxRadius(BoxRadius);
		MyRMP->SetNumPrimeNumbersToCalculate(NumPrimeNumbersToCalculate);
	}
}
