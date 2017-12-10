#pragma once

#include "CoreMinimal.h"
#include "GenericGraphNode.h"
#include "GenericGraphEdge.h"
#include "GameplayTagContainer.h"
#include "GenericGraph.generated.h"

UCLASS(Blueprintable)
class GENERICGRAPHRUNTIME_API UGenericGraph : public UObject
{
	GENERATED_BODY()

public:
	UGenericGraph();
	virtual ~UGenericGraph();

	UPROPERTY(EditDefaultsOnly, Category = "GenericGraph")
	FString Name;

	UPROPERTY(EditDefaultsOnly, Category = "GenericGraph")
	TSubclassOf<UGenericGraphNode> NodeType;

	UPROPERTY(EditDefaultsOnly, Category = "GenericGraph")
	TSubclassOf<UGenericGraphEdge> EdgeType;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GenericGraph")
	FGameplayTagContainer GraphTags;

	UPROPERTY(BlueprintReadOnly, Category = "GenericGraph")
	TArray<UGenericGraphNode*> RootNodes;

	UPROPERTY(BlueprintReadOnly, Category = "GenericGraph")
	TArray<UGenericGraphNode*> AllNodes;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GenericGraph")
	bool bEdgeEnabled;

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	class UEdGraph* EdGraph;

	UPROPERTY(EditDefaultsOnly, Category = "GenericGraph")
	bool bCanRenameNode;

	UPROPERTY(EditDefaultsOnly, Category = "AutoArrange")
	bool bRandomInit;

	UPROPERTY(EditDefaultsOnly, Category = "AutoArrange")
	float OptimalDistance;

	UPROPERTY(EditDefaultsOnly, Category = "AutoArrange")
	int32 MaxIteration;

	UPROPERTY(EditDefaultsOnly, Category = "AutoArrange")
	float InitTemperature;

	UPROPERTY(EditDefaultsOnly, Category = "AutoArrange")
	float CoolDownRate;
#endif

	UFUNCTION(BlueprintCallable, Category = "GenericGraph")
	void Print(bool ToConsole = true, bool ToScreen = true);

	UFUNCTION(BlueprintCallable, Category = "GenericGraph")
	int GetLevelNum() const;

	UFUNCTION(BlueprintCallable, Category = "GenericGraph")
	void GetNodesByLevel(int Level, TArray<UGenericGraphNode*>& Nodes);

	void ClearGraph();
};
