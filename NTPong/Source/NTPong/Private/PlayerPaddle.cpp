// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPaddle.h"
#include "..\Public\PlayerPaddle.h"


#include "DrawDebugHelpers.h"
#include "PaperSpriteComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/SpringArmComponent.h"


// Sets default values
APlayerPaddle::APlayerPaddle()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlayerRootCollisionBox = CreateDefaultSubobject<UBoxComponent>("Scene Root");
	SetRootComponent(PlayerRootCollisionBox);

	PlayerRootCollisionBox->SetBoxExtent(FVector(120, 50, 140));
	PlayerRootCollisionBox->SetSimulatePhysics(true);
	PlayerRootCollisionBox->SetNotifyRigidBodyCollision(true);
	PlayerRootCollisionBox->SetCollisionProfileName("BlockAll");
	PlayerRootCollisionBox->SetEnableGravity(false);
	PlayerRootCollisionBox->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);


	
	PlayerRootCollisionBox->GetBodyInstance()->bLockRotation = true;// BodyInstance.bLockXRotation = true; SetConstraintMode(EDOFMode::XZPlane)
	PlayerRootCollisionBox->GetBodyInstance()->bLockXRotation = true;
	PlayerRootCollisionBox->GetBodyInstance()->bLockYRotation = true;
	PlayerRootCollisionBox->GetBodyInstance()->bLockZRotation = true;
	PlayerRootCollisionBox->GetBodyInstance()->bLockYTranslation = true;
	PlayerRootCollisionBox->GetBodyInstance()->bLockXTranslation = true;
	
	
	PlayerPaddleSpriteComponent = CreateDefaultSubobject<UPaperSpriteComponent>("Pawn Sprite");
	PlayerPaddleSpriteComponent->SetCollisionProfileName("NoCollison");
	PlayerPaddleSpriteComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	PlayerPaddleSpriteComponent->SetupAttachment(RootComponent);
	
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraAttachmentArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritYaw = false;
	SpringArm->bInheritRoll = false;
	SpringArm->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.f));
	SpringArm->SocketOffset = FVector(0.0f, 0.0f, 0.0f);
	SpringArm->TargetArmLength = 500.0f;
	

	FollowCamera = CreateDefaultSubobject<UCameraComponent>("Pawns Camera");
	FollowCamera->SetProjectionMode(ECameraProjectionMode::Orthographic);
	FollowCamera->SetOrthoWidth(5000.0f);
	FollowCamera->SetupAttachment(SpringArm);
	FollowCamera->bUsePawnControlRotation = false;

	normalSpeed = 5;

	
}

// Called when the game starts or when spawned
void APlayerPaddle::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void APlayerPaddle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector NewLocation = GetActorLocation();
	//IF MovementForward NOT EQUAL to 0
	if (MovementUp != 0)
	{
		//ASSIGN NewLocation to the the sum of the Actors Current Location and the product of the Actors Forward Vector and the MovementForward value i.e GetActorLocation() + (GetActorForwardVector() * MovementForward)
		NewLocation = GetActorLocation() + (GetActorUpVector() * MovementUp * normalSpeed);
	}
	//ENDIF	

	//CALL SetActorLocation() passing in NewLocation
	SetActorLocation(NewLocation);

	
}

// Called to bind functionality to input
void APlayerPaddle::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveUp", this, &APlayerPaddle::MoveUp);

}

void APlayerPaddle::SetDirection(const FVector Direction)
{
	if (Direction == FVector::UpVector) {
		PlayerPaddleSpriteComponent->SetRelativeRotation(FRotator(0, 0, 0));
	}
	else if (Direction == FVector::DownVector) {
		PlayerPaddleSpriteComponent->SetRelativeRotation(FRotator(0, 180, 0));
	}
}


void APlayerPaddle::MoveUp(float value)
{
	MovementUp = value;

	
}

