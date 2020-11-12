// Fill out your copyright notice in the Description page of Project Settings.


#include "Board.h"


#include "DrawDebugHelpers.h"
#include "PaperSpriteComponent.h"
#include "Components/BoxComponent.h"


// Sets default values
ABoard::ABoard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoardSpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>("SceneRoot");
	SetRootComponent(BoardSpriteComponent);

	TopBorderline = CreateDefaultSubobject<UBoxComponent>("TopBox");
	TopBorderline->SetBoxExtent(FVector(120, 50, 140));
	TopBorderline->SetCollisionProfileName("BlockAll");
	TopBorderline->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);//Enable Query and physics collisions.
	TopBorderline->SetRelativeLocation(FVector(0.f, 0.f, -670.f));
	TopBorderline->SetupAttachment(RootComponent);

	BottomBorderline = CreateDefaultSubobject<UBoxComponent>("BottomBox");
	BottomBorderline->SetBoxExtent(FVector(120, 50, 140));
	BottomBorderline->SetCollisionProfileName("BlockAll");
	BottomBorderline->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);//Enable Query and physics collisions.
	BottomBorderline->SetupAttachment(RootComponent);

	PlayerGoal = CreateDefaultSubobject<UBoxComponent>("PlayerGoal");
	PlayerGoal->SetBoxExtent(FVector(120, 50, 140));//Set the box size
	PlayerGoal->SetSimulatePhysics(false);//Disable Physics on the box
	PlayerGoal->SetCollisionProfileName("OverlapAllDynamic");//Set this box to handle Overlap collisions
	PlayerGoal->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);//Enable Query and physics collisions.
	PlayerGoal->SetupAttachment(RootComponent);															  //Since we disable physic above.
																			  //It will only do Query
	
	PlayerGoal->OnComponentBeginOverlap.AddDynamic(this, &ABoard::BeginOverlap);
	PlayerGoal->OnComponentEndOverlap.AddDynamic(this, &ABoard::EndOverlap);

	AIGoal = CreateDefaultSubobject<UBoxComponent>("AIGoal");
	AIGoal->SetBoxExtent(FVector(120, 50, 140));//Set the box size
	AIGoal->SetSimulatePhysics(false);//Disable Physics on the box
	AIGoal->SetCollisionProfileName("OverlapAllDynamic");//Set this box to handle Overlap collisions
	AIGoal->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);//Enable Query and physics collisions.
	AIGoal->SetupAttachment(RootComponent);																		  //Since we disable physic above.
																			  //It will only do Query

	AIGoal->OnComponentBeginOverlap.AddDynamic(this, &ABoard::BeginOverlap);
	AIGoal->OnComponentEndOverlap.AddDynamic(this, &ABoard::EndOverlap);
	
}

// Called when the game starts or when spawned
void ABoard::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	DrawDebugBox(GetWorld(),
  TopBorderline->GetComponentLocation(),
		TopBorderline->GetScaledBoxExtent(),
		FColor::Green,
		true,
		999,
		0,
		5);

	DrawDebugBox(GetWorld(),
  BottomBorderline->GetComponentLocation(),
		BottomBorderline->GetScaledBoxExtent(),
		FColor::Green,
		true,
		999,
		0,
		5);
}

void ABoard::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 3.5, FColor::Green, TEXT("BeginOverlap Called"));
			GEngine->AddOnScreenDebugMessage(-1, 5., FColor::Magenta,
				FString::Printf(TEXT("Overlapping Actor = %s"), *OtherActor->GetName()));
		}
	}
}

void ABoard::EndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && OtherActor != this)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 3.5, FColor::Green, TEXT("EndOverlap Called"));
			GEngine->AddOnScreenDebugMessage(-1, 5., FColor::Magenta,
				FString::Printf(TEXT("Overlapping Actor = %s"), *OtherActor->GetName()));
		}

		//ABall* ball = Cast<ABall>(OtherActor);
		//if(ball)

		//if (OtherActor->IsA<ABall>())
		//{
		//	//ball->Destroy();
		//	OtherActor->Destroy();
		//}
	}
}