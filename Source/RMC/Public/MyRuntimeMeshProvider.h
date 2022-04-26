// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeMeshProvider.h"
#include "MyRuntimeMeshProvider.generated.h"

/**
 *
 */
UCLASS()
class RMC_API UMyRuntimeMeshProvider : public URuntimeMeshProvider
{
	GENERATED_BODY()

public:
	UMyRuntimeMeshProvider();

private:
	mutable FCriticalSection PropertySyncRoot;

	UPROPERTY(Category = "RuntimeMesh|Providers|Box", VisibleAnywhere, BlueprintGetter = GetBoxRadius, BlueprintSetter = SetBoxRadius)
		FVector BoxRadius;

	UPROPERTY(Category = "RuntimeMesh|Providers|Box", VisibleAnywhere, BlueprintGetter = GetBoxMaterial, BlueprintSetter = SetBoxMaterial)
		UMaterialInterface* Material;

	TArray<int> PrimeNumbers;
	int NumPrimeNumbersToCalculate;

public:
	UFUNCTION(Category = "RuntimeMesh|Providers|Box", BlueprintCallable)
		FVector GetBoxRadius() const;
	UFUNCTION(Category = "RuntimeMesh|Providers|Box", BlueprintCallable)
		void SetBoxRadius(const FVector& InRadius);

	UFUNCTION(Category = "RuntimeMesh|Providers|Box", BlueprintCallable)
		UMaterialInterface* GetBoxMaterial() const;
	UFUNCTION(Category = "RuntimeMesh|Providers|Box", BlueprintCallable)
		void SetBoxMaterial(UMaterialInterface* InMaterial);

	UFUNCTION(Category = "RuntimeMesh|Providers|Box", BlueprintCallable)
		void GetPrimeNumbers(TArray<int>& OutPrimeNumbers);

	UFUNCTION(Category = "RuntimeMesh|Providers|Box", BlueprintCallable)
		int GetNumPrimeNumbersToCalculate();

	UFUNCTION(Category = "RuntimeMesh|Providers|Box", BlueprintCallable)
		void SetNumPrimeNumbersToCalculate(int NumToCalc);

protected:
	void Initialize() override;
	FBoxSphereBounds GetBounds() override;
	bool GetSectionMeshForLOD(int32 LODIndex, int32 SectionId, FRuntimeMeshRenderableMeshData& MeshData) override;
	FRuntimeMeshCollisionSettings GetCollisionSettings() override;
	bool HasCollisionMesh() override;
	bool GetCollisionMesh(FRuntimeMeshCollisionData& CollisionData) override;
	bool IsThreadSafe() override;
};
