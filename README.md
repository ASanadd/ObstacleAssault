#  Obstacle Assault

A small 3D platforming prototype built in **Unreal Engine 5** with **C++**, exploring core gameplay programming concepts as part of my transition from automotive/systems C++ into game development.

---

## Preview

<img width="2039" height="1339" alt="Screenshot 2026-04-30 211825" src="https://github.com/user-attachments/assets/f983152e-a410-4e04-9fd9-8496863975a1" />

##  What This Project Demonstrates

This prototype focuses on the **fundamentals of Unreal C++ Actor programming**:

-  Unreal's Actor lifecycle (`BeginPlay`, `Tick`)
-  Frame-rate independent movement using `DeltaTime`
-  Vector and rotator math (`FVector`, `FRotator`)
-  Editor-exposed properties via `UPROPERTY` reflection
-  Defensive APIs (`GetSafeNormal()`)
-  Drift correction in oscillating motion

---

##  Implemented Systems

###  Moving Platform (`AMovingPlatform`)
A platform that translates between two points along a configurable velocity vector, with **overshoot correction** to prevent positional drift over many oscillations.

**Key logic:**
- Stores `StartLocation` at `BeginPlay`
- Each `Tick`, advances by `PlatformVelocity * DeltaTime`
- When distance from `StartLocation` exceeds `DistanceThreshold`:
  - Snaps the actor to the exact threshold position (no drift)
  - Reverses direction
  - Updates `StartLocation` to the far end for the next leg

**Editor-exposed parameters:**
| Property | Purpose |
|---|---|
| `PlatformVelocity` | Direction + speed (units/sec) |
| `DistanceThreshold` | Max distance before reversing |

###  Rotating Platform (`ARotatingPlatform`)
A platform that continuously rotates around its local axes at a configurable rotation rate.

**Key logic:**
- Uses `AddActorLocalRotation(RotationVelocity * DeltaTime)`
- Frame-rate independent — rotation rate stays consistent across hardware

**Editor-exposed parameters:**
| Property | Purpose |
|---|---|
| `RotationVelocity` | Pitch / Yaw / Roll per second (degrees) |

---

## Tech Stack

- **Engine**: Unreal Engine 5
- **Language**: C++17
- **IDE**: Visual Studio 2022
- **Build System**: Unreal Build Tool (UBT)

---

##  Running the Project

### Prerequisites
- Unreal Engine 5.x installed
- Visual Studio 2022 with **Game development with C++** workload
- Windows 10/11

### Steps
1. Clone the repository
   ```bash
   git clone https://github.com/ASanadd/ObstacleAssault.git
   ```
2. Right-click `ObstacleAssault.uproject` → **Generate Visual Studio project files**
3. Open the generated `.sln` in Visual Studio
4. Build the solution (`Ctrl + Shift + B`)
5. Open `ObstacleAssault.uproject` in Unreal Editor
6. Press **Play** ▶️

---

## Project Structure

```
ObstacleAssault/
├── Source/
│   └── ObstacleAssault/
│       ├── MovingPlatform.h        # Translating platform header
│       ├── MovingPlatform.cpp      # Translating platform logic
│       ├── RotatingPlatform.h      # Rotating platform header
│       └── RotatingPlatform.cpp    # Rotating platform logic
├── Content/                        # Levels, materials, blueprints
└── ObstacleAssault.uproject        # Unreal project file
```

---

##  About Me

I'm **Abdelrahman Sanad**, a C++ Software Engineer at **DXC Luxoft**, with ~1.5 years of experience in production automotive C++, embedded firmware, and Linux systems programming.

This project is part of my journey exploring **game development as a creative outlet** — and a way to broaden my engineering perspective beyond systems-level C++.

Connect: [LinkedIn](https://linkedin.com/in/abdelrahmansalah3)

---

## License

This project is open for educational and reference purposes. Feel free to explore, fork, or learn from it.

---

If you found this useful or interesting, a star is appreciated!
