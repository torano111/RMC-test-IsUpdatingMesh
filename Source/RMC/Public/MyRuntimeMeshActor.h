// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeMeshActor.h"
#include "MyRuntimeMeshActor.generated.h"

class UMyRuntimeMeshProvider;

UCLASS()
class RMC_API AMyRuntimeMeshActor : public ARuntimeMeshActor
{
	GENERATED_BODY()

protected:
	UPROPERTY()
		UMyRuntimeMeshProvider* MyRMP;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector BoxRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UMaterialInterface* BoxMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int NumPrimeNumbersToCalculate;

protected:
	void UpdateRMPProperties();

public:
	AMyRuntimeMeshActor(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintPure)
		bool IsUpdatingMesh() const { return GetRuntimeMeshComponent() ? GetRuntimeMeshComponent()->IsUpdatingMesh() : false; }

	UFUNCTION(BlueprintCallable)
		void InitializeRMC();

	UFUNCTION(BlueprintCallable)
		void UpdateRMC();

	UFUNCTION(BlueprintCallable)
		void GetPrimeNumbers(TArray<int>& OutPrimeNumbers);
};
