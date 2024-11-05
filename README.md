Detailed Feature Breakdown
1. Character System

    Class Types: Warrior, Mage, Archer, etc., each with unique base stats (health, attack, defense).
    Stats: Health, attack, defense, and any special attributes like agility or magic power.
    Leveling System: Character gains experience points (XP) from battles, leading to level-ups that increase stats.

2. Dungeon and Rooms

    Dungeon Layout: Each dungeon consists of 9 levels (rooms), with randomized monster spawns.
    Events: Each room has an event (monster encounter, loot, trap, or empty).
    Boss Room: The 9th room contains the dungeon boss.

3. Combat System

    Player Actions: Attack, use item, flee (fleeing may not always succeed).
    Turn-Based: Player and monster take turns until one side is defeated.
    Attack Mechanics: Simple attack calculation (e.g., attack - defense = damage).
    Special Abilities (optional): Classes may have unique abilities with cooldowns or resource costs.

4. Inventory and Equipment

    Inventory Management: Players can collect, equip, or discard items.
    Item Types:
        Weapons: Increase attack stat.
        Armor: Increase defense stat.
        Potions: Restore health or provide temporary stat boosts.
    Equip/Unequip: Equipped items affect character stats directly.

5. Monsters and Bosses

    Base Monsters: Each dungeon has a set of monsters with randomized stats (health, attack, defense).
    Bosses: Stronger enemies with unique stats and special abilities.
    Loot Drops: Monsters drop random items that the player can collect.

6. Save and Load System

    Auto-Save: Progress is saved after each room or combat.
    Manual Save: Option for players to save at any point outside combat.
    Load Game: Allows players to resume from the last save.



Development Roadmap
Phase 1: Core Structure and Basic Gameplay

    Project Setup
        Set up CMake and project structure.
        Configure Google Test for unit testing.

    Game Loop and GameState System
        Implement GameLoop with basic game states (Main Menu, In Game, Pause, Game Over).
        Set up MainMenuState and InGameState with simple transitions.

    Character and Stats System
        Create Character and Stats classes.
        Implement basic stats (health, attack, defense) and a leveling system.

    Dungeon and Room Generation
        Create basic dungeon structure with rooms.
        Implement randomized events (monster, loot, trap) for each room.

Phase 2: Combat and Inventory System

    Combat System
        Implement turn-based combat mechanics.
        Add player actions: attack, flee, use item.

    Inventory System
        Create Inventory class to manage items.
        Implement basic item types (weapon, armor, potion).
        Allow players to equip and unequip items.

    Monsters and Bosses
        Create Monster class with stats.
        Add boss logic for the 9th dungeon room.

Phase 3: Item and Equipment System

    Item Collection and Equipment
        Implement loot drops for monsters.
        Allow players to collect and manage items.
        Apply equipment effects to character stats.

    Inventory and Equipment Management
        Enable players to equip and unequip items.
        Implement stat changes based on equipped items.

Phase 4: Save and Load System

    Save Game System
        Implement save functionality (save character stats, inventory, dungeon progress).
        Use JSON or binary format for storing save data.

    Load Game System
        Implement load functionality to restore game state from a saved file.

Phase 5: Polish and Additional Features

    Main Menu Options
        Refine the main menu with options for starting a new game, loading a game, and quitting.

    Game Balancing
        Adjust monster stats, loot frequency, and item effects to ensure balanced gameplay.

    Testing and Debugging
        Write unit tests for key components (combat calculations, inventory, save/load).
        Perform playtesting to identify bugs and gameplay issues.

    Optional Enhancements
        Add additional classes or character abilities.
        Implement traps with random effects in dungeon rooms.
        Add special abilities for bosses.

