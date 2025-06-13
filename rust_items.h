#ifndef RUST_ITEMS_H
#define RUST_ITEMS_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

const char* RustItem_GetName(int id);
int RustItem_GetID(const char* name);
int RustItem_GetCount();

// Item ID Constants
#define ITEM_AUTO_TURRET -2139580305 // Auto Turret
#define ITEM_OUTBREAK_SCIENTIST_SUIT -2133781216 // Outbreak Scientist Suit
#define ITEM_ACOUSTIC_GUITAR -2124352573 // Acoustic Guitar
#define ITEM_ADVANCED_HEALING_TEA -2123125470 // Advanced Healing Tea
#define ITEM_BAMBOO_SALVAGED_SHELVES -2110553371 // Bamboo Salvaged Shelves
#define ITEM_SHOVEL_BASS -2107018088 // Shovel Bass
#define ITEM_SUNGLASSES -2103694546 // Sunglasses
#define ITEM_RAW_SNAKE_MEAT -2100458529 // Raw Snake Meat
#define ITEM_STONES -2099697608 // Stones
#define ITEM_NAILGUN_NAILS -2097376851 // Nailgun Nails
#define ITEM_RAW_BIG_CAT_MEAT -2095813057 // Raw Big Cat Meat
#define ITEM_WOOD_ARMOR_HELMET -2094954543 // Wood Armor Helmet
#define ITEM_POTATO -2086926071 // Potato
#define ITEM_POTATO_SEED -2084071424 // Potato Seed
#define ITEM_SKINNING_KNIFE -2073432256 // Skinning Knife
#define ITEM_BANDAGE -2072273936 // Bandage
#define ITEM_M249 -2069578888 // M249
#define ITEM_SHEET_METAL_DOOR -2067472972 // Sheet Metal Door
#define ITEM_SMALL_CANDLE_SET -2058362263 // Small Candle Set
#define ITEM_PRESSURE_PAD -2049214035 // Pressure Pad
#define ITEM_MOVEMBER_MOUSTACHE -2047081330 // Movember Moustache
#define ITEM_PAN_FLUTE -2040817543 // Pan Flute
#define ITEM_SPOILED_DEER_MEAT -2035449523 // Spoiled Deer Meat
#define ITEM_LOCOMOTIVE -2027988285 // Locomotive
#define ITEM_ADVENT_CALENDAR -2027793839 // Advent Calendar
#define ITEM_BASEBALL_BAT -2026042603 // Baseball Bat
#define ITEM_SHIRT -2025184684 // Shirt
#define ITEM_HEAVY_FRANKENSTEIN_LEGS -2024549027 // Heavy Frankenstein Legs
#define ITEM_DIVING_TANK -2022172587 // Diving Tank
#define ITEM_CHICKEN_COOP -2018158920 // Chicken Coop
#define ITEM_LUNAR_WALL_FRAME_FLORAL -2016974826 // Lunar Wall Frame Floral
#define ITEM_IMPROVISED_BALACLAVA -2012470695 // Improvised Balaclava
#define ITEM_ROAD_SIGN_JACKET -2002277461 // Road Sign Jacket
#define ITEM_INSTANT_CAMERA -2001260025 // Instant Camera
#define ITEM_FURNACE -1999722522 // Furnace
#define ITEM_SUNGLASSES_2 -1997698639 // Sunglasses
#define ITEM_HORSE_SADDLE -1997543660 // Horse Saddle
#define ITEM_SHEET_METAL -1994909036 // Sheet Metal
#define ITEM_LARGE_FURNACE -1992717673 // Large Furnace
#define ITEM_HOT_AIR_BALLOON_ARMOR -1989600732 // Hot Air Balloon Armor
#define ITEM_INCENDIARY_BOLT -1987565603 // Incendiary Bolt
#define ITEM_RUG -1985799200 // Rug
#define ITEM_HIGH_QUALITY_METAL_ORE -1982036270 // High Quality Metal Ore
#define ITEM_SALVAGED_CLEAVER -1978999529 // Salvaged Cleaver
#define ITEM_FOGGER_3000 -1973785141 // Fogger-3000
#define ITEM_MACE -1966748496 // Mace
#define ITEM_MUSHROOM -1962971928 // Mushroom
#define ITEM_FIRECRACKER_STRING -1961560162 // Firecracker String
#define ITEM_SCIENTIST_SUIT -1958316066 // Scientist Suit
#define ITEM_CONCRETE_BARRICADE -1950721390 // Concrete Barricade
#define ITEM_ICE_THRONE -1944704288 // Ice Throne
#define ITEM_CAN_OF_TUNA -1941646328 // Can of Tuna
#define ITEM_CHARCOAL -1938052175 // Charcoal
#define ITEM_HALF_HEIGHT_BAMBOO_SHELVES -1923843855 // Half Height Bamboo Shelves
#define ITEM_CHINESE_LANTERN -1916473915 // Chinese Lantern
#define ITEM_FISH_TROPHY -1913996738 // Fish Trophy
#define ITEM_ORANGE_ROUGHY -1904821376 // Orange Roughy
#define ITEM_BONE_HELMET -1903165497 // Bone Helmet
#define ITEM_GOLD_FRAME_MEDIUM -1901993050 // Gold Frame Medium
#define ITEM_GLUE -1899491405 // Glue
#define ITEM_SCRAP_TRANSPORT_HELICOPTER -1884328185 // Scrap Transport Helicopter
#define ITEM_RED_KEYCARD -1880870149 // Red Keycard
#define ITEM_FLATBED_VEHICLE_MODULE -1880231361 // Flatbed Vehicle Module
#define ITEM_SMALL_TROUT -1878764039 // Small Trout
#define ITEM_SATCHEL_CHARGE -1878475007 // Satchel Charge
#define ITEM_WATER_BARREL -1863559151 // Water Barrel
#define ITEM_ROCKING_CHAIR -1863063690 // Rocking Chair
#define ITEM_RESEARCH_TABLE -1861522751 // Research Table
#define ITEM_SILENCER -1850571427 // Silencer
#define ITEM_COOKED_CHICKEN -1848736516 // Cooked Chicken
#define ITEM_MLRS_ROCKET -1843426638 // MLRS Rocket
#define ITEM_HIGH_VELOCITY_ROCKET -1841918730 // High Velocity Rocket
#define ITEM_GOLD_FRAME_SMALL -1836526520 // Gold Frame Small
#define ITEM_ONE_SIDED_TOWN_SIGN_POST -1832422579 // One Sided Town Sign Post
#define ITEM_PROPANE_EXPLOSIVE_BOMB -1827561369 // Propane Explosive Bomb
#define ITEM_JACK_O_LANTERN_HAPPY -1824943010 // Jack O Lantern Happy
#define ITEM_SKY_LANTERN_ORANGE -1824770114 // Sky Lantern - Orange
#define ITEM_WIND_TURBINE -1819763926 // Wind Turbine
#define ITEM_MEDIUM_WOODEN_SIGN -1819233322 // Medium Wooden Sign
#define ITEM_WATER_PISTOL -1815301988 // Water Pistol
#define ITEM_LR_300_ASSAULT_RIFLE -1812555177 // LR-300 Assault Rifle
#define ITEM_BEEHIVE_NUCLEUS -1811234677 // Beehive Nucleus
#define ITEM_GOLD_MIRROR_MEDIUM -1804515496 // Gold Mirror Medium
#define ITEM_HIGH_QUALITY_VALVES -1802083073 // High Quality Valves
#define ITEM_SPEARGUN_SPEAR -1800345240 // Speargun Spear
#define ITEM_SPOILED_CROCODILE_MEAT -1796837031 // Spoiled Crocodile Meat
#define ITEM_WHEAT_SEED -1790885730 // Wheat Seed
#define ITEM_FISH_PIE -1785248332 // Fish Pie
#define ITEM_SURGEON_SCRUBS -1785231475 // Surgeon Scrubs
#define ITEM_SALVAGED_ICEPICK -1780802565 // Salvaged Icepick
#define ITEM_PAPER -1779183908 // Paper
#define ITEM_WATER -1779180711 // Water
#define ITEM_BUTTON -1778897469 // Button
#define ITEM_HEAVY_PLATE_PANTS -1778159885 // Heavy Plate Pants
#define ITEM_GREEN_BERRY_SEED -1776128552 // Green Berry Seed
#define ITEM_SCRAP_FRAME_STANDING -1774190142 // Scrap Frame Standing
#define ITEM_HIDE_SKIRT -1773144852 // Hide Skirt
#define ITEM_HEAVY_SCIENTIST_SUIT -1772746857 // Heavy Scientist Suit
#define ITEM_SKY_LANTERN_GREEN -1770889433 // Sky Lantern - Green
#define ITEM_SMALL_SHARK -1768880890 // Small Shark
#define ITEM_GAS_COMPRESSION_OVERDRIVE -1767794021 // Gas Compression Overdrive
#define ITEM_HOT_AIR_BALLOON -1759188988 // Hot Air Balloon
#define ITEM_THOMPSON -1758372725 // Thompson
#define ITEM_SLEEPING_BAG -1754948969 // Sleeping Bag
#define ITEM_REACTIVE_TARGET -1736356576 // Reactive Target
#define ITEM_MEDIUM_FRANKENSTEIN_HEAD -1732475823 // Medium Frankenstein Head
#define ITEM_ADVANCED_ANTI_RAD_TEA -1729415579 // Advanced Anti-Rad Tea
#define ITEM_RAW_HUMAN_MEAT -1709878924 // Raw Human Meat
#define ITEM_FISHING_TACKLE -1707425764 // Fishing Tackle
#define ITEM_HERRING -1698937385 // Herring
#define ITEM_HAZMAT_YOUTOOZ -1696379844 // Hazmat Youtooz
#define ITEM_SHORTS -1695367501 // Shorts
#define ITEM_LARGE_FLATBED_VEHICLE_MODULE -1693832478 // Large Flatbed Vehicle Module
#define ITEM_HV_PISTOL_AMMO -1691396643 // HV Pistol Ammo
#define ITEM_12_GAUGE_BUCKSHOT -1685290200 // 12 Gauge Buckshot
#define ITEM_TWO_WAY_MIRROR -1683726934 // Two-Way Mirror
#define ITEM_GRAVEYARD_FENCE -1679267738 // Graveyard Fence
#define ITEM_PURE_HEALING_TEA -1677315902 // Pure Healing Tea
#define ITEM_EMPTY_PROPANE_TANK -1673693549 // Empty Propane Tank
#define ITEM_TORPEDO -1671551935 // Torpedo
#define ITEM_DECORATIVE_BAUBELS -1667224349 // Decorative Baubels
#define ITEM_HOMEMADE_LANDMINE -1663759755 // Homemade Landmine
#define ITEM_MEDIEVAL_SHEET_METAL_DOOR -1654401345 // Medieval Sheet Metal Door
#define ITEM_SARDINE -1654233406 // Sardine
#define ITEM_BAMBOO_BARREL -1652561344 // Bamboo Barrel
#define ITEM_POOKIE_BEAR -1651220691 // Pookie Bear
#define ITEM_TWO_SIDED_ORNATE_HANGING_SIGN -1647846966 // Two Sided Ornate Hanging Sign
#define ITEM_FRANKENSTEIN_MASK -1647389398 // Frankenstein Mask
#define ITEM_LIGHT_FRANKENSTEIN_TORSO -1624770297 // Light Frankenstein Torso
#define ITEM_LARGE_PRESENT -1622660759 // Large Present
#define ITEM_BANDIT_GUARD_GEAR -1622110948 // Bandit Guard Gear
#define ITEM_BEACH_PARASOL -1621539785 // Beach Parasol
#define ITEM_SPOILED_SNAKE_MEAT -1616704051 // Spoiled Snake Meat
#define ITEM_ARMORED_PASSENGER_VEHICLE_MODULE -1615281216 // Armored Passenger Vehicle Module
#define ITEM_STRENGTHENED_GLASS_WINDOW -1614955425 // Strengthened Glass Window
#define ITEM_WORKBENCH_LEVEL_3 -1607980696 // Workbench Level 3
#define ITEM_COMPUTER_STATION -1588628467 // Computer Station
#define ITEM_STONE_HATCHET -1583967946 // Stone Hatchet
#define ITEM_SULFUR -1581843485 // Sulfur
#define ITEM_HORSE_DUNG -1579932985 // Horse Dung
#define ITEM_HEADSET -1569700847 // Headset
#define ITEM_EMPTY_TUNA_CAN -1557377697 // Empty Tuna Can
#define ITEM_RED_BOOMER -1553999294 // Red Boomer
#define ITEM_BOOTS -1549739227 // Boots
#define ITEM_WOOD_FRAME_MEDIUM -1541706279 // Wood Frame Medium
#define ITEM_MINERS_HAT -1539025626 // Miners Hat
#define ITEM_VIOLET_VOLCANO_FIREWORK -1538109120 // Violet Volcano Firework
#define ITEM_SHOVEL -1536855921 // Shovel
#define ITEM_STONE_FIREPLACE -1535621066 // Stone Fireplace
#define ITEM_CASSETTE_RECORDER -1530414568 // Cassette Recorder
#define ITEM_GOLD_FRAME_STANDING -1528767189 // Gold Frame Standing
#define ITEM_RAW_BEAR_MEAT -1520560807 // Raw Bear Meat
#define ITEM_DROP_BOX -1519126340 // Drop Box
#define ITEM_NIGHT_VISION_GOGGLES -1518883088 // Night Vision Goggles
#define ITEM_SPEARGUN -1517740219 // Speargun
#define ITEM_HONEYCOMB -1513203236 // Honeycomb
#define ITEM_PUMPKIN_SEED -1511285251 // Pumpkin Seed
#define ITEM_COOKED_DEER_MEAT -1509851560 // Cooked Deer Meat
#define ITEM_HBHF_SENSOR -1507239837 // HBHF Sensor
#define ITEM_NINJA_SUIT -1506417026 // Ninja Suit
#define ITEM_SALVAGED_HAMMER -1506397857 // Salvaged Hammer
#define ITEM_COCKPIT_VEHICLE_MODULE -1501451746 // Cockpit Vehicle Module
#define ITEM_WALLPAPER -1501434104 // Wallpaper
#define ITEM_WOOD_MIRROR_SMALL -1497205569 // Wood Mirror Small
#define ITEM_PUMPKIN_PIE -1488408786 // Pumpkin Pie
#define ITEM_COMPOSTER -1488398114 // Composter
#define ITEM_RED_ROMAN_CANDLE -1486461488 // Red Roman Candle
#define ITEM_ICE_METAL_CHEST_PLATE -1478855279 // Ice Metal Chest Plate
#define ITEM_TUNA_CAN_LAMP -1478445584 // Tuna Can Lamp
#define ITEM_WOLF_HEADDRESS -1478212975 // Wolf Headdress
#define ITEM_BOOGIE_BOARD -1478094705 // Boogie Board
#define ITEM_WOOD_FRAME_SMALL -1476278729 // Wood Frame Small
#define ITEM_LONGSWORD -1469578201 // Longsword
#define ITEM_MLRS -1449152644 // MLRS
#define ITEM_ELECTRICAL_BRANCH -1448252298 // Electrical Branch
#define ITEM_GOLD_MIRROR_SMALL -1444650226 // Gold Mirror Small
#define ITEM_HOBO_BARREL -1442559428 // Hobo Barrel
#define ITEM_PINATA -1442496789 // Pinata
#define ITEM_RAW_CHICKEN_BREAST -1440987069 // Raw Chicken Breast
#define ITEM_SKY_LANTERN_RED -1433390281 // Sky Lantern - Red
#define ITEM_ANTI_RADIATION_PILLS -1432674913 // Anti-Radiation Pills
#define ITEM_PRISON_CELL_WALL -1429456799 // Prison Cell Wall
#define ITEM_MEDIUM_NEON_SIGN -1423304443 // Medium Neon Sign
#define ITEM_STORAGE_BARREL_HORIZONTAL -1421257350 // Storage Barrel Horizontal
#define ITEM_MOTORBIKE -1417478274 // Motorbike
#define ITEM_WALKIE_TALKIE -1416322465 // Walkie Talkie
#define ITEM_SUNGLASSES_3 -1408336705 // Sunglasses
#define ITEM_MUZZLE_BOOST -1405508498 // Muzzle Boost
#define ITEM_PURPLE_ID_TAG -1386082991 // Purple ID Tag
#define ITEM_SCRAP_MIRROR_STANDING -1380144986 // Scrap Mirror Standing
#define ITEM_FESTIVE_WINDOW_GARLAND -1379835144 // Festive Window Garland
#define ITEM_CANBOURINE -1379036069 // Canbourine
#define ITEM_PORTRAIT_PICTURE_FRAME -1370759135 // Portrait Picture Frame
#define ITEM_SICKLE -1368584029 // Sickle
#define ITEM_WATERPIPE_SHOTGUN -1367281941 // Waterpipe Shotgun
#define ITEM_SPRAY_CAN_DECAL -1366326648 // Spray Can Decal
#define ITEM_SNOWMOBILE -1364246987 // Snowmobile
#define ITEM_CONCRETE_PICKAXE -1360171080 // Concrete Pickaxe
#define ITEM_WANTED_POSTER -1344017968 // Wanted Poster
#define ITEM_WOOD_DOUBLE_DOOR -1336109173 // Wood Double Door
#define ITEM_ICE_ASSAULT_RIFLE -1335497659 // Ice Assault Rifle
#define ITEM_HOCKEY_MASK -1334569149 // Hockey Mask
#define ITEM_STAR_TREE_TOPPER -1331212963 // Star Tree Topper
#define ITEM_JUNKYARD_DRUM_KIT -1330640246 // Junkyard Drum Kit
#define ITEM_DOUBLE_HORSE_SADDLE -1323101799 // Double Horse Saddle
#define ITEM_EXPLOSIVE_5_56_RIFLE_AMMO -1321651331 // Explosive 5.56 Rifle Ammo
#define ITEM_COOKED_BIG_CAT_MEAT -1318837358 // Cooked Big Cat Meat
#define ITEM_CAMERA -1316706473 // Camera
#define ITEM_DRAGON_ROCKET_LAUNCHER -1315992997 // Dragon Rocket Launcher
#define ITEM_SNAKE_MASK -1314079879 // Snake mask
#define ITEM_LEGACY_FURNACE -1310391395 // Legacy Furnace
#define ITEM_GREEN_ROMAN_CANDLE -1306288356 // Green Roman Candle
#define ITEM_GREEN_BERRY_CLONE -1305326964 // Green Berry Clone
#define ITEM_PICKAXE -1302129395 // Pickaxe
#define ITEM_LIGHT_UP_FRAME_MEDIUM -1294739579 // Light-Up Frame Medium
#define ITEM_SMALL_OIL_REFINERY -1293296287 // Small Oil Refinery
#define ITEM_SIEGE_TOWER -1290278434 // Siege Tower
#define ITEM_OR_SWITCH -1286302544 // OR Switch
#define ITEM_WATER_PUMP -1284169891 // Water Pump
#define ITEM_BATH_TUB_PLANTER -1274093662 // Bath Tub Planter
#define ITEM_BED -1273339005 // Bed
#define ITEM_BUNNY_ONESIE -1266045928 // Bunny Onesie
#define ITEM_WANTED_POSTER_3 -1265020883 // Wanted Poster 3
#define ITEM_BINOCULARS -1262185308 // Binoculars
#define ITEM_COOLING_TEA -1260229965 // Cooling Tea
#define ITEM_HATCHET -1252059217 // Hatchet
#define ITEM_WOODEN_ARROW -1234735557 // Wooden Arrow
#define ITEM_FESTIVE_DOUBLE_DOORWAY_GARLAND -1230433643 // Festive Double Doorway Garland
#define ITEM_FLAME_THROWER -1215753368 // Flame Thrower
#define ITEM_A_BARREL_COSTUME -1215166612 // A Barrel Costume
#define ITEM_HMLMG -1214542497 // HMLMG
#define ITEM_BASIC_HORSE_SHOES -1211268013 // Basic Horse Shoes
#define ITEM_5_56_RIFLE_AMMO -1211166256 // 5.56 Rifle Ammo
#define ITEM_METAL_VERTICAL_EMBRASURE -1199897172 // Metal Vertical embrasure
#define ITEM_METAL_HORIZONTAL_EMBRASURE -1199897169 // Metal horizontal embrasure
#define ITEM_ELECTRIC_FURNACE -1196547867 // Electric Furnace
#define ITEM_BASIC_MAX_HEALTH_TEA -1184406448 // Basic Max Health Tea
#define ITEM_WOODEN_WINDOW_BARS -1183726687 // Wooden Window Bars
#define ITEM_CULTIST_DEER_TORCH -1175656359 // Cultist Deer Torch
#define ITEM_SPOILED_WOLF_MEAT -1167031859 // Spoiled Wolf Meat
#define ITEM_FLUID_SPLITTER -1166712463 // Fluid Splitter
#define ITEM_WEAPON_RACK_LIGHT -1163943815 // Weapon Rack Light
#define ITEM_JACKET -1163532624 // Jacket
#define ITEM_COOKED_HORSE_MEAT -1162759543 // Cooked Horse Meat
#define ITEM_RED_INDUSTRIAL_WALL_LIGHT -1160621614 // Red Industrial Wall Light
#define ITEM_SULFUR_ORE -1157596551 // Sulfur Ore
#define ITEM_WOODEN_FRONTIER_BAR_DOORS -1151332840 // Wooden Frontier Bar Doors
#define ITEM_WARMING_TEA -1142222427 // Warming Tea
#define ITEM_SMALL_WOODEN_SIGN -1138208076 // Small Wooden Sign
#define ITEM_MACHETE -1137865085 // Machete
#define ITEM_PUMP_JACK -1130709577 // Pump Jack
#define ITEM_RAW_HORSE_MEAT -1130350864 // Raw Horse Meat
#define ITEM_PIERCER_BOLT -1127003365 // Piercer Bolt
#define ITEM_MULTIPLE_GRENADE_LAUNCHER -1123473824 // Multiple Grenade Launcher
#define ITEM_CHAINLINK_FENCE -1117626326 // Chainlink Fence
#define ITEM_BOOM_BOX -1113501606 // Boom Box
#define ITEM_DOOR_KEY -1112793865 // Door Key
#define ITEM_TACTICAL_GLOVES -1108136649 // Tactical Gloves
#define ITEM_RUG_BEAR_SKIN -1104881824 // Rug Bear Skin
#define ITEM_HEAVY_PLATE_JACKET -1102429027 // Heavy Plate Jacket
#define ITEM_WETSUIT -1101924344 // Wetsuit
#define ITEM_SPINNING_WHEEL -1100422738 // Spinning wheel
#define ITEM_LARGE_WATER_CATCHER -1100168350 // Large Water Catcher
#define ITEM_SCRAP_FRAME_LARGE -1094453063 // Scrap Frame large
#define ITEM_RAW_CROCODILE_MEAT -1081599445 // Raw Crocodile Meat
#define ITEM_SKULL_SPIKES -1078639462 // Skull Spikes
#define ITEM_SKULL_SPIKES_2 -1073015016 // Skull Spikes
#define ITEM_SCRAP_FRAME_MEDIUM -1060567807 // Scrap Frame Medium
#define ITEM_DIVER_PROPULSION_VEHICLE -1056824343 // Diver propulsion vehicle
#define ITEM_SCRAP_MIRROR_SMALL -1050697733 // Scrap Mirror Small
#define ITEM_COWBELL -1049881973 // Cowbell
#define ITEM_STORAGE_ADAPTOR -1049172752 // Storage Adaptor
#define ITEM_RF_BROADCASTER -1044468317 // RF Broadcaster
#define ITEM_GHOST_COSTUME -1043618880 // Ghost Costume
#define ITEM_CAMPER_VEHICLE_MODULE -1040518150 // Camper Vehicle Module
#define ITEM_SMALL_WATER_BOTTLE -1039528932 // Small Water Bottle
#define ITEM_ROSE_SEED -1037472336 // Rose Seed
#define ITEM_12_GAUGE_INCENDIARY_SHELL -1036635990 // 12 Gauge Incendiary Shell
#define ITEM_WOOD_SHUTTERS -1023374709 // Wood Shutters
#define ITEM_HIGH_VELOCITY_ARROW -1023065463 // High Velocity Arrow
#define ITEM_BASEBALL_CAP -1022661119 // Baseball Cap
#define ITEM_METAL_SPRING -1021495308 // Metal Spring
#define ITEM_ANIMAL_FAT -1018587433 // Animal Fat
#define ITEM_SAM_SITE -1009359066 // SAM Site
#define ITEM_BUNNY_EARS -1004426654 // Bunny Ears
#define ITEM_SUPER_SERUM -1003665711 // Super Serum
#define ITEM_GOLD_EGG -1002156085 // Gold Egg
#define ITEM_FROG_BOOTS -1000573653 // Frog Boots
#define ITEM_BLUEPRINT -996920608 // Blueprint
#define ITEM_GOLD_FRAME_LARGE -996235148 // Gold Frame large
#define ITEM_XL_PICTURE_FRAME -996185386 // XL Picture Frame
#define ITEM_WHITE_BERRY_SEED -992286106 // White Berry Seed
#define ITEM_BURNT_BEAR_MEAT -989755543 // Burnt Bear Meat
#define ITEM_RABBIT_MASK -986782031 // Rabbit Mask
#define ITEM_HIGH_ICE_WALL -985781766 // High Ice Wall
#define ITEM_JERRY_CAN_GUITAR -979951147 // Jerry Can Guitar
#define ITEM_EASTER_DOOR_WREATH -979302481 // Easter Door Wreath
#define ITEM_HIGH_EXTERNAL_STONE_WALL -967648160 // High External Stone Wall
#define ITEM_CHOCOLATE_BAR -965336208 // Chocolate Bar
#define ITEM_SURVIVOR_S_PIE -963820355 // Survivor's Pie
#define ITEM_INCAPACITATE_DART -963819285 // Incapacitate Dart
#define ITEM_NEW_YEAR_GONG -961457160 // New Year Gong
#define ITEM_PRISON_CELL_GATE -956706906 // Prison Cell Gate
#define ITEM_SEISMIC_SENSOR -948291630 // Seismic Sensor
#define ITEM_LOW_GRADE_FUEL -946369541 // Low Grade Fuel
#define ITEM_KNIGHTS_ARMOUR_SKIRT_PLATES -945708533 // Knights armour skirt plates
#define ITEM_FLASHER_LIGHT -939424778 // Flasher Light
#define ITEM_FLASHBANG -936921910 // Flashbang
#define ITEM_SCRAP -932201673 // Scrap
#define ITEM_FERTILIZER -930193596 // Fertilizer
#define ITEM_BASIC_HEALING_TEA -929092070 // Basic Healing Tea
#define ITEM_SKULL_TROPHY -924959988 // Skull Trophy
#define ITEM_CASSETTE_MEDIUM -912398867 // Cassette - Medium
#define ITEM_LARGE_BACKPACK -907422733 // Large Backpack
#define ITEM_SEMI_AUTOMATIC_RIFLE -904863145 // Semi-Automatic Rifle
#define ITEM_ASBESTOS_ARMOR_INSERT -903796529 // Asbestos Armor Insert
#define ITEM_TWITCH_RIVALS_TROPHY_2023 -901370585 // Twitch Rivals Trophy 2023
#define ITEM_PRISONER_HOOD -892718768 // Prisoner Hood
#define ITEM_HALLOWEEN_CANDY -888153050 // Halloween Candy
#define ITEM_HEMP_CLONE -886280491 // Hemp Clone
#define ITEM_VAMPIRE_STAKE -885833256 // Vampire Stake
#define ITEM_BLUNDERBUSS -880412831 // Blunderbuss
#define ITEM_WATERWELL_NPC_JUMPSUIT -874908751 // Waterwell NPC Jumpsuit
#define ITEM_SNAKE_VENOM -870140677 // Snake Venom
#define ITEM_SMALL_HUNTING_TROPHY -869598982 // Small Hunting Trophy
#define ITEM_CLOTH -858312878 // Cloth
#define ITEM_SIMPLE_HANDMADE_SIGHT -855748505 // Simple Handmade Sight
#define ITEM_DRAGON_DOOR_KNOCKER -854270928 // Dragon Door Knocker
#define ITEM_M92_PISTOL -852563019 // M92 Pistol
#define ITEM_SALMON -851988960 // Salmon
#define ITEM_BLOW_PIPE -851288382 // Blow Pipe
#define ITEM_KEY_LOCK -850982208 // Key Lock
#define ITEM_FRONTIER_HORSESHOE_SINGLE_ITEM_RACK -849373693 // Frontier Horseshoe Single Item Rack
#define ITEM_LANDSCAPE_PICTURE_FRAME -845557339 // Landscape Picture Frame
#define ITEM_SNOWMAN_HELMET -842267147 // Snowman Helmet
#define ITEM_HANDCUFFS -839576748 // Handcuffs
#define ITEM_METAL_WINDOW_BARS -819720157 // Metal Window Bars
#define ITEM_WORK_CART -810326667 // Work Cart
#define ITEM_PLANT_FIBER -804769727 // Plant Fiber
#define ITEM_COFFEE_CAN_HELMET -803263829 // Coffee Can Helmet
#define ITEM_ORCHID_CLONE -798662404 // Orchid Clone
#define ITEM_LASER_DETECTOR -798293154 // Laser Detector
#define ITEM_ABYSS_DIVERS_SUIT -797592358 // Abyss Divers Suit
#define ITEM_SHOP_FRONT -796583652 // Shop Front
#define ITEM_ELECTRIC_HEATER -784870360 // Electric Heater
#define ITEM_SPRINKLER -781014061 // Sprinkler
#define ITEM_CORN_CLONE -778875547 // Corn Clone
#define ITEM_L96_RIFLE -778367295 // L96 Rifle
#define ITEM_CHINESE_LANTERN_WHITE -770304148 // Chinese Lantern White
#define ITEM_SKULL_TROPHY_2 -769647921 // Skull Trophy
#define ITEM_DOUBLE_BARREL_SHOTGUN -765183617 // Double Barrel Shotgun
#define ITEM_LUMBERJACK_HOODIE -763071910 // Lumberjack Hoodie
#define ITEM_BURLAP_SHOES -761829530 // Burlap Shoes
#define ITEM_MOUNTED_BALLISTA -759279626 // Mounted Ballista
#define ITEM_SPOILED_CHICKEN -751151717 // Spoiled Chicken
#define ITEM_EGG_SUIT -747743875 // Egg Suit
#define ITEM_MEMORY_CELL -746647361 // Memory Cell
#define ITEM_GRANOLA_BAR -746030907 // Granola Bar
#define ITEM_ROCKET -742865266 // Rocket
#define ITEM_TWITCH_RIVALS_FLAG -739993590 // Twitch Rivals Flag
#define ITEM_PADDLING_POOL -733625651 // Paddling Pool
#define ITEM_12_GAUGE_SLUG -727717969 // 12 Gauge Slug
#define ITEM_SPOILED_HORSE_MEAT -724146494 // Spoiled Horse Meat
#define ITEM_HEAVY_SCIENTIST_YOUTOOZ -722629980 // Heavy Scientist Youtooz
#define ITEM_SMALL_PRESENT -722241321 // Small Present
#define ITEM_BANDANA_MASK -702051347 // Bandana Mask
#define ITEM_CAN_OF_BEANS -700591459 // Can of Beans
#define ITEM_ROADSIGN_GLOVES -699558439 // Roadsign Gloves
#define ITEM_INNER_TUBE -697981032 // Inner Tube
#define ITEM_SMART_ALARM -695978112 // Smart Alarm
#define ITEM_GIANT_CANDY_DECOR -695124222 // Giant Candy Decor
#define ITEM_SMALL_RECHARGEABLE_BATTERY -692338819 // Small Rechargeable Battery
#define ITEM_HIGH_EXTERNAL_STONE_GATE -691113464 // High External Stone Gate
#define ITEM_BLOCKER -690968985 // Blocker
#define ITEM_GLOWING_EYES -690276911 // Glowing Eyes
#define ITEM_BURNT_HUMAN_MEAT -682687162 // Burnt Human Meat
#define ITEM_GREEN_BOOMER -656349006 // Green Boomer
#define ITEM_BASIC_WOOD_TEA -649128577 // Basic Wood Tea
#define ITEM_WOOD_FRAME_LARGE -635951327 // Wood Frame Large
#define ITEM_ELECTRIC_FUSE -629028935 // Electric Fuse
#define ITEM_TAXI_VEHICLE_MODULE -626174997 // Taxi Vehicle Module
#define ITEM_SUNFLOWER -611118083 // Sunflower
#define ITEM_RED_DOG_TAGS -602717596 // Red Dog Tags
#define ITEM_SPRAY_CAN -596876839 // Spray Can
#define ITEM_RADIATION_DART -594596146 // Radiation Dart
#define ITEM_WOODEN_ARMOR_INSERT -593892112 // Wooden Armor Insert
#define ITEM_EXPLOSIVES -592016202 // Explosives
#define ITEM_CATFISH -587989372 // Catfish
#define ITEM_MAIL_BOX -586784898 // Mail Box
#define ITEM_BLUEBERRIES -586342290 // Blueberries
#define ITEM_MEGAPHONE -583379016 // Megaphone
#define ITEM_SNAP_TRAP -582782051 // Snap Trap
#define ITEM_COCONUT_ARMOR_HELMET -582467439 // Coconut Armor Helmet
#define ITEM_PARTY_HAT -575744869 // Party Hat
#define ITEM_SANTA_HAT -575483084 // Santa Hat
#define ITEM_GRUB -568419968 // Grub
#define ITEM_PUMPKIN -567909622 // Pumpkin
#define ITEM_RF_PAGER -566907190 // RF Pager
#define ITEM_SPLITTER -563624462 // Splitter
#define ITEM_TUGBOAT -561148628 // Tugboat
#define ITEM_SPACE_SUIT -560304835 // Space Suit
#define ITEM_SANDBAG_BARRICADE -559599960 // Sandbag Barricade
#define ITEM_GINGERBREAD_SUIT -558880549 // Gingerbread Suit
#define ITEM_PURE_WOOD_TEA -557539629 // Pure Wood Tea
#define ITEM_SOFA -555122905 // Sofa
#define ITEM_RESEARCH_PAPER -544317637 // Research Paper
#define ITEM_MINNOWS -542577259 // Minnows
#define ITEM_ADVANCED_WOOD_TEA -541206665 // Advanced Wood Tea
#define ITEM_WICKER_BARREL -526026171 // Wicker Barrel
#define ITEM_YELLOW_BERRY_SEED -520133715 // Yellow Berry Seed
#define ITEM_BLUE_ROMAN_CANDLE -515830359 // Blue Roman Candle
#define ITEM_WELLIPETS_HAT -507248640 // Wellipets Hat
#define ITEM_DOOR_CONTROLLER -502177121 // Door Controller
#define ITEM_SCRAP_FRAME_SMALL -498301781 // Scrap Frame Small
#define ITEM_RAD_REMOVAL_TEA -496584751 // Rad. Removal Tea
#define ITEM_MEDIUM_QUALITY_SPARK_PLUGS -493159321 // Medium Quality Spark Plugs
#define ITEM_LARGE_CANDLE_SET -489848205 // Large Candle Set
#define ITEM_BASIC_ANTI_RAD_TEA -487356515 // Basic Anti-Rad Tea
#define ITEM_BLUE_KEYCARD -484206264 // Blue Keycard
#define ITEM_FIREBOMB -484006286 // Firebomb
#define ITEM_MINI_CROSSBOW -482348853 // Mini Crossbow
#define ITEM_BATTERING_RAM_HEAD -479314201 // Battering Ram Head
#define ITEM_ARCTIC_SUIT -470439097 // Arctic Suit
#define ITEM_SUPER_STOCKING -465682601 // SUPER Stocking
#define ITEM_WATCH_TOWER -463122489 // Watch Tower
#define ITEM_WOOD_ARMOR_GLOVES -459159118 // Wood Armor Gloves
#define ITEM_ROOT_COMBINER -458565393 // Root Combiner
#define ITEM_GRAY_ID_TAG -455286320 // Gray ID Tag
#define ITEM_RED_VOLCANO_FIREWORK -454370658 // Red Volcano Firework
#define ITEM_LUNAR_WALL_FRAME_SWIRLING -450890885 // Lunar Wall Frame Swirling
#define ITEM_SINGLE_PLANT_POT -430416124 // Single Plant Pot
#define ITEM_KNIGHTS_ARMOUR_HELMET -427072335 // Knights armour helmet
#define ITEM_MEDIEVAL_BARRICADE -424687710 // Medieval Barricade
#define ITEM_HIGH_EXTERNAL_ADOBE_GATE -401905610 // High External Adobe Gate
#define ITEM_PROTOTYPE_HATCHET -399173933 // Prototype Hatchet
#define ITEM_RAW_WOLF_MEAT -395377963 // Raw Wolf Meat
#define ITEM_EGG_SUIT_SIGN_TEST -394470247 // Egg Suit Sign Test
#define ITEM_LIGHT_UP_MIRROR_SMALL -389796733 // Light-Up Mirror Small
#define ITEM_SAM_AMMO -384243979 // SAM Ammo
#define ITEM_MEDIEVAL_SHEET_METAL_DOUBLE_DOOR -380502678 // Medieval Sheet Metal Double Door
#define ITEM_PATTERN_BOOMER -379734527 // Pattern Boomer
#define ITEM_SMALL_STASH -369760990 // Small Stash
#define ITEM_POWERED_WATER_PURIFIER -365097295 // Powered Water Purifier
#define ITEM_SNOWBALL -363689972 // Snowball
#define ITEM_BONE_DART -361911645 // Bone Dart
#define ITEM_PITCHFORK_BOLT -357442017 // Pitchfork Bolt
#define ITEM_SKS -348232115 // SKS
#define ITEM_SOUND_LIGHT -343857907 // Sound Light
#define ITEM_HIGH_EXTERNAL_WOODEN_GATE -335089230 // High External Wooden Gate
#define ITEM_SLED -333406828 // Sled
#define ITEM_REINDEER_ANTLERS -324675402 // Reindeer Antlers
#define ITEM_CRUDE_OIL -321733511 // Crude Oil
#define ITEM_BEACH_CHAIR -321431890 // Beach Chair
#define ITEM_WOODEN_LADDER -316250604 // Wooden Ladder
#define ITEM_HEAVY_FRANKENSTEIN_HEAD -297099594 // Heavy Frankenstein Head
#define ITEM_TEST_GENERATOR -295829489 // Test Generator
#define ITEM_ORANGE_ID_TAG -282193997 // Orange ID Tag
#define ITEM_SIMPLE_LIGHT -282113991 // Simple Light
#define ITEM_TRIANGLE_PLANTER_BOX -280812482 // Triangle Planter Box
#define ITEM_VIOLET_BOOMER -280223496 // Violet Boomer
#define ITEM_SALT_WATER -277057363 // Salt Water
#define ITEM_WOOD_DART -274709858 // Wood Dart
#define ITEM_GUN_POWDER -265876753 // Gun Powder
#define ITEM_FLUID_COMBINER -265292885 // Fluid Combiner
#define ITEM_SALVAGED_AXE -262590403 // Salvaged Axe
#define ITEM_DRACULA_CAPE -258574361 // Dracula Cape
#define ITEM_UNUSED_STORAGE_BARREL_VERTICAL -258457936 // Unused Storage Barrel Vertical
#define ITEM_SCIENTIST_SUIT_2 -253079493 // Scientist Suit
#define ITEM_HORIZONTAL_WEAPON_RACK -246672609 // Horizontal Weapon Rack
#define ITEM_TWITCH_RIVALS_DESK -243540612 // Twitch Rivals Desk
#define ITEM_COOKED_PORK -242084766 // Cooked Pork
#define ITEM_SURFACE_TORPEDO -239306133 // Surface torpedo
#define ITEM_HEMP_SEED -237809779 // Hemp Seed
#define ITEM_HOMING_MISSILE_LAUNCHER -218009552 // Homing Missile Launcher
#define ITEM_COUNTER -216999575 // Counter
#define ITEM_SKULL_DOOR_KNOCKER -216116642 // Skull Door Knocker
#define ITEM_XYLOBONE -211235948 // Xylobone
#define ITEM_DECORATIVE_PLASTIC_CANDY_CANES -209869746 // Decorative Plastic Candy Canes
#define ITEM_FLASHLIGHT -196667575 // Flashlight
#define ITEM_METAL_FACEMASK -194953424 // Metal Facemask
#define ITEM_BUTCHER_KNIFE -194509282 // Butcher Knife
#define ITEM_SINGLE_SHALLOW_WALL_SHELVES -193519904 // Single Shallow Wall Shelves
#define ITEM_BATTERING_RAM -187304968 // Battering Ram
#define ITEM_SOLO_SUBMARINE -187031121 // Solo Submarine
#define ITEM_WOOD_STORAGE_BOX -180129657 // Wood Storage Box
#define ITEM_SUNGLASSES_4 -176608084 // Sunglasses
#define ITEM_RUSTIG_EGG_BLUE -173268132 // Rustig� Egg - Blue
#define ITEM_RUSTIG_EGG_PURPLE -173268131 // Rustig� Egg - Purple
#define ITEM_RUSTIG_EGG_RED -173268129 // Rustig� Egg - Red
#define ITEM_RUSTIG_EGG_WHITE -173268128 // Rustig� Egg - White
#define ITEM_RUSTIG_EGG_CERULEAN -173268127 // Rustig� Egg - Cerulean
#define ITEM_RUSTIG_EGG_IVORY -173268126 // Rustig� Egg - Ivory
#define ITEM_RUSTIG_EGG_GREEN -173268125 // Rustig� Egg - Green
#define ITEM_COOKED_SNAKE_MEAT -170436364 // Cooked Snake Meat
#define ITEM_SKULL_TROPHY_3 -156748077 // Skull Trophy
#define ITEM_CHICKEN_COSTUME -152332823 // Chicken Costume
#define ITEM_WOOD -151838493 // Wood
#define ITEM_DELUXE_CHRISTMAS_LIGHTS -151387974 // Deluxe Christmas Lights
#define ITEM_GARAGE_DOOR -148794216 // Garage Door
#define ITEM_METAL_SHOP_FRONT -148229307 // Metal Shop Front
#define ITEM_PIPE_TOOL -144513264 // Pipe Tool
#define ITEM_WIRE_TOOL -144417939 // Wire Tool
#define ITEM_HUGE_WOODEN_SIGN -143132326 // Huge Wooden Sign
#define ITEM_ABYSS_ASSAULT_RIFLE -139037392 // Abyss Assault Rifle
#define ITEM_SLED_2 -135252633 // Sled
#define ITEM_LIGHT_FRANKENSTEIN_HEAD -134959124 // Light Frankenstein Head
#define ITEM_WEAPON_LASERSIGHT -132516482 // Weapon Lasersight
#define ITEM_SMALL_WATER_CATCHER -132247350 // Small Water Catcher
#define ITEM_DECORATIVE_PINECONES -129230242 // Decorative Pinecones
#define ITEM_PAINTED_EGG -126305173 // Painted Egg
#define ITEM_WATER_JUG -119235651 // Water Jug
#define ITEM_DIVING_MASK -113413047 // Diving Mask
#define ITEM_LOCKER -110921842 // Locker
#define ITEM_FRONTIER_SUIT -105415879 // Frontier Suit
#define ITEM_VIOLET_ROMAN_CANDLE -99886070 // Violet Roman Candle
#define ITEM_TOOL_CUPBOARD -97956382 // Tool Cupboard
#define ITEM_JUMPSUIT -97459906 // Jumpsuit
#define ITEM_WIDE_WEAPON_RACK -96256997 // Wide Weapon Rack
#define ITEM_WOODEN_FLOOR_SPIKES -92759291 // Wooden Floor Spikes
#define ITEM_HIGH_CALIBER_REVOLVER -92315244 // High Caliber Revolver
#define ITEM_LOW_QUALITY_SPARK_PLUGS -89874794 // Low Quality Spark Plugs
#define ITEM_SCRAP_MIRROR_LARGE -82758111 // Scrap Mirror Large
#define ITEM_BRICK_SKIN_WINDOW_BARS -81700958 // Brick Skin Window Bars
#define ITEM_BURNT_DEER_MEAT -78533081 // Burnt Deer Meat
#define ITEM_EOKA_PISTOL -75944661 // Eoka Pistol
#define ITEM_LEGACY_BOW -73195037 // Legacy bow
#define ITEM_FRONTIER_HORNS_SINGLE_ITEM_RACK -52398594 // Frontier Horns Single Item Rack
#define ITEM_SNOW_JACKET -48090175 // Snow Jacket
#define ITEM_IGNITER -44876289 // Igniter
#define ITEM_MEDIUM_CHASSIS -44066823 // Medium Chassis
#define ITEM_LARGE_CHASSIS -44066790 // Large Chassis
#define ITEM_SMALL_CHASSIS -44066600 // Small Chassis
#define ITEM_WORKBENCH_LEVEL_2 -41896755 // Workbench Level 2
#define ITEM_SPAS_12_SHOTGUN -41440462 // Spas-12 Shotgun
#define ITEM_PURE_ANTI_RAD_TEA -33009419 // Pure Anti-Rad Tea
#define ITEM_SKULL_SPIKES_3 -25740268 // Skull Spikes
#define ITEM_BOONIE_HAT -23994173 // Boonie Hat
#define ITEM_DRAGON_MASK -22883916 // Dragon Mask
#define ITEM_MOBILE_PHONE -20045316 // Mobile Phone
#define ITEM_ROSE_CLONE -19360132 // Rose Clone
#define ITEM_HAMMERHEAD_BOLT -19318653 // Hammerhead Bolt
#define ITEM_SMOKE_ROCKET_WIP -17123659 // Smoke Rocket WIP!!!!
#define ITEM_BEACH_TOWEL -8312704 // Beach Towel
#define ITEM_ORANGE_BOOMER -7270019 // Orange Boomer
#define ITEM_METAL_ORE -4031221 // Metal Ore
#define ITEM_HIDE_HALTERNECK 3222790 // Hide Halterneck
#define ITEM_CARD_MOVEMBER_MOUSTACHE 3380160 // Card Movember Moustache
#define ITEM_APPLE_PIE 4384538 // Apple Pie
#define ITEM_FIRE_ARROW 14241751 // Fire Arrow
#define ITEM_STONE_BARRICADE 15388698 // Stone Barricade
#define ITEM_PURPLE_SUNGLASSES 20489901 // Purple Sunglasses
#define ITEM_BURLAP_GLOVES 21402876 // Burlap Gloves
#define ITEM_WHITE_ID_TAG 22947882 // White ID Tag
#define ITEM_LARGE_BANNER_HANGING 23352662 // Large Banner Hanging
#define ITEM_BUNNY_HAT 23391694 // Bunny Hat
#define ITEM_M39_RIFLE 28201841 // M39 Rifle
#define ITEM_GREEN_KEYCARD 37122747 // Green Keycard
#define ITEM_MICROPHONE_STAND 39600618 // Microphone Stand
#define ITEM_MEDIUM_ANIMATED_NEON_SIGN 42535890 // Medium Animated Neon Sign
#define ITEM_INCENDIARY_PISTOL_BULLET 51984655 // Incendiary Pistol Bullet
#define ITEM_CROCODILE_PIE 54265286 // Crocodile Pie
#define ITEM_ROADSIGN_HORSE_ARMOR 60528587 // Roadsign Horse Armor
#define ITEM_PHOTOGRAPH 62577426 // Photograph
#define ITEM_HIGH_EXTERNAL_FRONTIER_WALL 63265850 // High External Frontier Wall
#define ITEM_METAL_FRAGMENTS 69511070 // Metal Fragments
#define ITEM_RED_ID_TAG 70102328 // Red ID Tag
#define ITEM_TECH_TRASH 73681876 // Tech Trash
#define ITEM_YELLOW_ID_TAG 81423963 // Yellow ID Tag
#define ITEM_NVGM_SCIENTIST_SUIT 86840834 // NVGM Scientist Suit
#define ITEM_METAL_PIPE 95950017 // Metal Pipe
#define ITEM_XXL_PICTURE_FRAME 98508942 // XXL Picture Frame
#define ITEM_HIGH_EXTERNAL_WOODEN_WALL 99588025 // High External Wooden Wall
#define ITEM_LIGHT_FRANKENSTEIN_LEGS 106959911 // Light Frankenstein Legs
#define ITEM_ICE_METAL_FACEMASK 110116923 // Ice Metal Facemask
#define ITEM_CHICKEN_PIE 120820987 // Chicken Pie
#define ITEM_TALL_PICTURE_FRAME 121049755 // Tall Picture Frame
#define ITEM_BLACK_BERRY_CLONE 122783240 // Black Berry Clone
#define ITEM_PTZ_CCTV_CAMERA 140006625 // PTZ CCTV Camera
#define ITEM_F1_GRENADE 143803535 // F1 Grenade
#define ITEM_OBSIDIAN_BONE_KNIFE 158303804 // Obsidian Bone Knife
#define ITEM_COCKPIT_WITH_ENGINE_VEHICLE_MODULE 170758448 // Cockpit With Engine Vehicle Module
#define ITEM_STONE_PICKAXE 171931394 // Stone Pickaxe
#define ITEM_VARIABLE_ZOOM_SCOPE 174866732 // Variable Zoom Scope
#define ITEM_RIFLE_BODY 176787552 // Rifle Body
#define ITEM_SCARECROW 177226991 // Scarecrow
#define ITEM_PINK_ID_TAG 180752235 // Pink ID Tag
#define ITEM_BEEHIVE 184516676 // Beehive
#define ITEM_INNER_TUBE_2 185586769 // Inner Tube
#define ITEM_KAYAK 190184021 // Kayak
#define ITEM_GREEN 192249897 // Green
#define ITEM_HIDE_VEST 196700171 // Hide Vest
#define ITEM_IMPROVISED_SHIELD 196784377 // Improvised Shield
#define ITEM_VENDING_MACHINE 198438816 // Vending Machine
#define ITEM_HAMMER 200773292 // Hammer
#define ITEM_COAL 204391461 // Coal :(
#define ITEM_WRAPPED_GIFT 204970153 // Wrapped Gift
#define ITEM_HEAD_BAG 209218760 // Head Bag
#define ITEM_ENGINEERING_WORKBENCH 210787554 // Engineering Workbench
#define ITEM_BONE_ARROW 215754713 // Bone Arrow
#define ITEM_T_SHIRT 223891266 // T-Shirt
#define ITEM_PROTOTYPE_PICKAXE 236677901 // Prototype Pickaxe
#define ITEM_PANTS 237239288 // Pants
#define ITEM_TALL_WEAPON_RACK 240752557 // Tall Weapon Rack
#define ITEM_LIGHT_UP_FRAME_LARGE 242421166 // Light-Up Frame Large
#define ITEM_FRONTIER_MIRROR_LARGE 242933621 // Frontier Mirror Large
#define ITEM_SPOILED_BIG_CAT_MEAT 248643189 // Spoiled Big Cat Meat
#define ITEM_LARGE_MEDKIT 254522515 // Large Medkit
#define ITEM_WHITE_VOLCANO_FIREWORK 261913429 // White Volcano Firework
#define ITEM_BASIC_SCRAP_TEA 263834859 // Basic Scrap Tea
#define ITEM_STORAGE_VEHICLE_MODULE 268565518 // Storage Vehicle Module
#define ITEM_RAT_MASK 271048478 // Rat Mask
#define ITEM_PLUMBER_S_TRUMPET 273172220 // Plumber's Trumpet
#define ITEM_SCARECROW_SUIT 273951840 // Scarecrow Suit
#define ITEM_MUMMY_SUIT 277730763 // Mummy Suit
#define ITEM_BREAD_LOAF 281099360 // Bread Loaf
#define ITEM_GIANT_LOLLIPOP_DECOR 282103175 // Giant Lollipop Decor
#define ITEM_PICKLES 286193827 // Pickles
#define ITEM_DISCO_FLOOR 286648290 // Disco Floor
#define ITEM_DIVING_FINS 296519935 // Diving Fins
#define ITEM_WANTED_POSTER_2 301063058 // Wanted Poster 2
#define ITEM_FLARE 304481038 // Flare
#define ITEM_BIG_CAT_PIE 309017792 // Big Cat Pie
#define ITEM_HIGH_QUALITY_METAL 317398316 // High Quality Metal
#define ITEM_HUNTERS_PIE 320438357 // Hunters Pie
#define ITEM_FRONTIER_MIRROR_SMALL 340210699 // Frontier Mirror Small
#define ITEM_ANCHOVY 342438846 // Anchovy
#define ITEM_MLRS_AIMING_MODULE 343045591 // MLRS Aiming Module
#define ITEM_40MM_HE_GRENADE 349762871 // 40mm HE Grenade
#define ITEM_ROTTEN_APPLE 352130972 // Rotten Apple
#define ITEM_SUNGLASSES_5 352321488 // Sunglasses
#define ITEM_SHOTGUN_TRAP 352499047 // Shotgun Trap
#define ITEM_MINIGUN_AMMO_PACK 355877490 // Minigun Ammo Pack
#define ITEM_CHIPPY_ARCADE_GAME 359723196 // Chippy Arcade Game
#define ITEM_HOSE_TOOL 363163265 // Hose Tool
#define ITEM_CRAFTING_QUALITY_TEA 368008432 // Crafting Quality Tea
#define ITEM_YELLOW_BERRY_CLONE 390728933 // Yellow Berry Clone
#define ITEM_COOKED_CROCODILE_MEAT 392828520 // Cooked Crocodile Meat
#define ITEM_WOOD_CHESTPLATE 418081930 // Wood Chestplate
#define ITEM_HOLOSIGHT 442289265 // Holosight
#define ITEM_ROCKET_LAUNCHER 442886268 // Rocket Launcher
#define ITEM_FLUID_SWITCH_PUMP 443432036 // Fluid Switch & Pump
#define ITEM_TORCH_HOLDER 446206234 // Torch Holder
#define ITEM_LIGHT_UP_MIRROR_LARGE 450531685 // Light-Up Mirror Large
#define ITEM_TWITCH_RIVALS_HAZMAT_SUIT 468313189 // Twitch Rivals Hazmat Suit
#define ITEM_MEDIEVAL_ASSAULT_RIFLE 472505338 // Medieval Assault Rifle
#define ITEM_CASSETTE_LONG 476066818 // Cassette - Long
#define ITEM_GEARS 479143914 // Gears
#define ITEM_LARGE_LOOT_BAG 479292118 // Large Loot Bag
#define ITEM_CLAN_TABLE 486661382 // Clan Table
#define ITEM_NOMAD_SUIT 491263800 // Nomad Suit
#define ITEM_RAND_SWITCH 492357192 // RAND Switch
#define ITEM_ICE_SCULPTURE 504109620 // Ice Sculpture
#define ITEM_COCONUT_ARMOR_PANTS 507284030 // Coconut Armor Pants
#define ITEM_ADVANCED_SCRAP_TEA 524678627 // Advanced Scrap Tea
#define ITEM_FLAME_TURRET 528668503 // Flame Turret
#define ITEM_KNIGHTS_ARMOUR_CUIRASS 547862680 // Knights armour cuirass
#define ITEM_LARGE_RECHARGEABLE_BATTERY 553270375 // Large Rechargeable Battery
#define ITEM_SKULL_FIRE_PIT 553887414 // Skull Fire Pit
#define ITEM_SURVIVAL_FISH_TRAP 559147458 // Survival Fish Trap
#define ITEM_8X_ZOOM_SCOPE 567235583 // 8x Zoom Scope
#define ITEM_SECRETLAB_CHAIR 567871954 // Secretlab Chair
#define ITEM_COFFIN 573676040 // Coffin
#define ITEM_SEMI_AUTOMATIC_BODY 573926264 // Semi Automatic Body
#define ITEM_PORTABLE_BOOM_BOX 576509618 // Portable Boom Box
#define ITEM_HANDMADE_SHELL 588596902 // Handmade Shell
#define ITEM_TABLE 593465182 // Table
#define ITEM_RF_TRANSMITTER 596469572 // RF Transmitter
#define ITEM_PARACHUTE 602628465 // Parachute
#define ITEM_BURLAP_SHIRT 602741290 // Burlap Shirt
#define ITEM_ADVANCED_MAX_HEALTH_TEA 603811464 // Advanced Max Health Tea
#define ITEM_INCENDIARY_5_56_RIFLE_AMMO 605467368 // Incendiary 5.56 Rifle Ammo
#define ITEM_LEGACY_WOOD_SHELTER 607400343 // Legacy Wood Shelter
#define ITEM_BATTERY_SMALL 609049394 // Battery - Small
#define ITEM_INDUSTRIAL_CONVEYOR 610102428 // Industrial Conveyor
#define ITEM_BOTA_BAG 613961768 // Bota Bag
#define ITEM_RAIL_ROAD_PLANTER 615112838 // Rail Road Planter
#define ITEM_RAW_PORK 621915341 // Raw Pork
#define ITEM_METAL_SHIELD 625599716 // Metal Shield
#define ITEM_CCTV_CAMERA 634478325 // CCTV Camera
#define ITEM_STICKS 642482233 // Sticks
#define ITEM_TRIANGLE_RAIL_ROAD_PLANTER 647240052 // Triangle Rail Road Planter
#define ITEM_REVOLVER 649912614 // Revolver
#define ITEM_HIGH_QUALITY_CARBURETOR 656371026 // High Quality Carburetor
#define ITEM_MEDIUM_QUALITY_CARBURETOR 656371027 // Medium Quality Carburetor
#define ITEM_LOW_QUALITY_CARBURETOR 656371028 // Low Quality Carburetor
#define ITEM_BEACH_TABLE 657352755 // Beach Table
#define ITEM_TIMER 665332906 // Timer
#define ITEM_RIOT_HELMET 671063303 // Riot Helmet
#define ITEM_REINFORCED_GLASS_WINDOW 671706427 // Reinforced Glass Window
#define ITEM_FESTIVE_DOORWAY_GARLAND 674734128 // Festive Doorway Garland
#define ITEM_M4_SHOTGUN 678698219 // M4 Shotgun
#define ITEM_YELLOW_PERCH 680234026 // Yellow Perch
#define ITEM_LUNAR_NEW_YEAR_SPEAR 695450239 // Lunar New Year Spear
#define ITEM_PAPER_MAP 696029452 // Paper Map
#define ITEM_WOODEN_CROSS 699075597 // Wooden Cross
#define ITEM_MILITARY_FLAME_THROWER 703057617 // Military Flame Thrower
#define ITEM_TIGER_MASK 709206314 // Tiger Mask
#define ITEM_CAR_RADIO 721798950 // Car Radio
#define ITEM_WATER_GUN 722955039 // Water Gun
#define ITEM_WOOD_MIRROR_STANDING 723407026 // Wood Mirror Standing
#define ITEM_ORCHID 734320711 // Orchid
#define ITEM_INDUSTRIAL_SPLITTER 742745918 // Industrial Splitter
#define ITEM_VODKA_BOTTLE 755224797 // Vodka Bottle
#define ITEM_WOOD_MIRROR_MEDIUM 756125481 // Wood Mirror Medium
#define ITEM_MEDIUM_PRESENT 756517185 // Medium Present
#define ITEM_HIGH_EXTERNAL_ADOBE_WALL 756890702 // High External Adobe Wall
#define ITEM_SIREN_LIGHT 762289806 // Siren Light
#define ITEM_SOFA_PATTERN 782422285 // Sofa - Pattern
#define ITEM_PISTOL_BULLET 785728077 // Pistol Bullet
#define ITEM_SUNKEN_COMBAT_KNIFE 789333045 // Sunken Combat Knife
#define ITEM_HIDE_BOOTS 794356786 // Hide Boots
#define ITEM_CHRISTMAS_TREE 794443127 // Christmas Tree
#define ITEM_TORCH 795236088 // Torch
#define ITEM_PUMP_SHOTGUN 795371088 // Pump Shotgun
#define ITEM_REPAIR_BENCH 803222026 // Repair Bench
#define ITEM_BLUE_BERRY_SEED 803954639 // Blue Berry Seed
#define ITEM_GRAVESTONE 809199956 // Gravestone
#define ITEM_MUMMY_MASK 809689733 // Mummy Mask
#define ITEM_SCARECROW_WRAP 809942731 // Scarecrow Wrap
#define ITEM_COOKED_WOLF_MEAT 813023040 // Cooked Wolf Meat
#define ITEM_MEDIEVAL_LARGE_WOOD_BOX 814297925 // Medieval Large Wood Box
#define ITEM_INDUSTRIAL_DOOR 818733919 // Industrial Door
#define ITEM_SEMI_AUTOMATIC_PISTOL 818877484 // Semi-Automatic Pistol
#define ITEM_BICYCLE 821588319 // Bicycle
#define ITEM_TWO_SIDED_TOWN_SIGN_POST 826309791 // Two Sided Town Sign Post
#define ITEM_RED_BERRY_SEED 830839496 // Red Berry Seed
#define ITEM_SKY_LANTERN_PURPLE 831955134 // Sky Lantern - Purple
#define ITEM_WOOD_ARMOR_PANTS 832133926 // Wood Armor Pants
#define ITEM_LARGE_WOOD_BOX 833533164 // Large Wood Box
#define ITEM_MEDIUM_FRANKENSTEIN_LEGS 835042040 // Medium Frankenstein Legs
#define ITEM_BURST_MODULE 838308300 // Burst Module
#define ITEM_BLUE_BERRY_CLONE 838831151 // Blue Berry Clone
#define ITEM_SCRAP_MIRROR_MEDIUM 839738457 // Scrap Mirror Medium
#define ITEM_BRONZE_EGG 844440409 // Bronze Egg
#define ITEM_BUCKET_HELMET 850280505 // Bucket Helmet
#define ITEM_LASER_LIGHT 853471967 // Laser Light
#define ITEM_WHITE_BERRY 854447607 // White Berry
#define ITEM_GREEN_BERRY 858486327 // Green Berry
#define ITEM_LUMBERJACK_SUIT 861513346 // Lumberjack Suit
#define ITEM_LARGE_NEON_SIGN 866332017 // Large Neon Sign
#define ITEM_WOODEN_BARRICADE 866889860 // Wooden Barricade
#define ITEM_GENERIC_VEHICLE_MODULE 878301596 // Generic vehicle module
#define ITEM_SPIDER_WEBS 882559853 // Spider Webs
#define ITEM_COMPOUND_BOW 884424049 // Compound Bow
#define ITEM_RF_RECEIVER 888415708 // RF Receiver
#define ITEM_PASSENGER_VEHICLE_MODULE 895374329 // Passenger Vehicle Module
#define ITEM_SUNFLOWER_CLONE 912235912 // Sunflower Clone
#define ITEM_40MM_SMOKE_GRENADE 915408809 // 40mm Smoke Grenade
#define ITEM_WHEAT_CLONE 924598634 // Wheat Clone
#define ITEM_MEDIUM_QUALITY_VALVES 926800282 // Medium Quality Valves
#define ITEM_MINIGUN 935606207 // Minigun
#define ITEM_LONGSLEEVE_T_SHIRT 935692442 // Longsleeve T-Shirt
#define ITEM_FLOOR_GRILL 936496778 // Floor grill
#define ITEM_CAR_KEY 946662961 // Car Key
#define ITEM_WEAPON_FLASHLIGHT 952603248 // Weapon flashlight
#define ITEM_LARGE_HUNTING_TROPHY 960673498 // Large Hunting Trophy
#define ITEM_TIN_CAN_ALARM 962186730 // Tin Can Alarm
#define ITEM_ROCK 963906841 // Rock
#define ITEM_CLATTER_HELMET 968019378 // Clatter Helmet
#define ITEM_CONNECTED_SPEAKER 968421290 // Connected Speaker
#define ITEM_REINFORCED_WOODEN_SHIELD 969768382 // Reinforced Wooden Shield
#define ITEM_SKULL_TROPHY_4 971362526 // Skull Trophy
#define ITEM_TWITCH_RIVALS_TROPHY 975983052 // Twitch Rivals Trophy
#define ITEM_HIDE_PONCHO 980333378 // Hide Poncho
#define ITEM_SMART_SWITCH 988652725 // Smart Switch
#define ITEM_RAW_FISH 989925924 // Raw Fish
#define ITEM_HUMAN_SKULL 996293980 // Human Skull
#define ITEM_WAGON 996757362 // Wagon
#define ITEM_CORN_SEED 998894949 // Corn Seed
#define ITEM_GEIGER_COUNTER 999690781 // Geiger Counter
#define ITEM_ORCHID_SEED 1004843240 // Orchid Seed
#define ITEM_DUO_SUBMARINE 1015352446 // Duo Submarine
#define ITEM_LIGHT_UP_MIRROR_MEDIUM 1028889957 // Light-Up Mirror Medium
#define ITEM_BLUE_DOG_TAGS 1036321299 // Blue Dog Tags
#define ITEM_ABYSS_METAL_HATCHET 1046904719 // Abyss Metal Hatchet
#define ITEM_MINING_QUARRY 1052926200 // Mining Quarry
#define ITEM_40MM_SHOTGUN_ROUND 1055319033 // 40mm Shotgun Round
#define ITEM_CHRISTMAS_LIGHTS 1058261682 // Christmas Lights
#define ITEM_HIGH_QUALITY_SPARK_PLUGS 1072924620 // High Quality Spark Plugs
#define ITEM_MEDICAL_SYRINGE 1079279582 // Medical Syringe
#define ITEM_NEST_HAT 1081315464 // Nest Hat
#define ITEM_CARD_TABLE 1081921512 // Card Table
#define ITEM_PITCHFORK 1090916276 // Pitchfork
#define ITEM_WRAPPING_PAPER 1094293920 // Wrapping Paper
#define ITEM_BARBEQUE 1099314009 // Barbeque
#define ITEM_METAL_ARMOR_INSERT 1099611828 // Metal Armor Insert
#define ITEM_SNOWBALL_GUN 1103488722 // Snowball Gun
#define ITEM_CHAINSAW 1104520648 // Chainsaw
#define ITEM_ARCTIC_SCIENTIST_SUIT 1107575710 // Arctic Scientist Suit
#define ITEM_METAL_CHEST_PLATE 1110385766 // Metal Chest Plate
#define ITEM_BLUE_BERRY 1112162468 // Blue Berry
#define ITEM_ATTACK_HELICOPTER 1113514903 // Attack Helicopter
#define ITEM_LUNAR_WALL_FRAME_INLAY 1115193056 // Lunar Wall Frame Inlay
#define ITEM_CANDY_CANE 1121925526 // Candy Cane
#define ITEM_SPOILED_FISH_MEAT 1130729138 // Spoiled Fish Meat
#define ITEM_WEAPON_RACK_STAND 1132603396 // Weapon Rack Stand
#define ITEM_CEILING_LIGHT 1142993169 // Ceiling Light
#define ITEM_CATAPULT 1145722690 // Catapult
#define ITEM_STORAGE_MONITOR 1149964039 // Storage Monitor
#define ITEM_LARGE_WOODEN_SIGN 1153652756 // Large Wooden Sign
#define ITEM_MEDIUM_QUALITY_CRANKSHAFT 1158340331 // Medium Quality Crankshaft
#define ITEM_HIGH_QUALITY_CRANKSHAFT 1158340332 // High Quality Crankshaft
#define ITEM_LOW_QUALITY_CRANKSHAFT 1158340334 // Low Quality Crankshaft
#define ITEM_CODE_LOCK 1159991980 // Code Lock
#define ITEM_HITCH_TROUGH 1160881421 // Hitch & Trough
#define ITEM_METAL_DETECTOR 1168856825 // Metal Detector
#define ITEM_BEE_GRENADE 1168916338 // Bee Grenade
#define ITEM_AND_SWITCH 1171735914 // AND Switch
#define ITEM_SHOCKBYTE_TOOL_CUPBOARD 1174957864 // Shockbyte Tool Cupboard
#define ITEM_CONCRETE_HATCHET 1176355476 // Concrete Hatchet
#define ITEM_ELEVATOR 1177596584 // Elevator
#define ITEM_WHEAT 1178325727 // Wheat
#define ITEM_HEAVY_PLATE_HELMET 1181207482 // Heavy Plate Helmet
#define ITEM_FUEL_TANK_VEHICLE_MODULE 1186655046 // Fuel Tank Vehicle Module
#define ITEM_CRATE_COSTUME 1189981699 // Crate Costume
#define ITEM_ROAD_SIGNS 1199391518 // Road Signs
#define ITEM_LARGE_PHOTO_FRAME 1205084994 // Large Photo Frame
#define ITEM_TWO_SIDED_HANGING_SIGN 1205607945 // Two Sided Hanging Sign
#define ITEM_ARMORED_DOUBLE_DOOR 1221063409 // Armored Double Door
#define ITEM_LAVENDER_ID_TAG 1223729384 // Lavender ID Tag
#define ITEM_DOG_TAG 1223900335 // Dog Tag
#define ITEM_SMG_BODY 1230323789 // SMG Body
#define ITEM_CAPTAIN_S_LOG 1230691307 // Captain's Log
#define ITEM_TELEPHONE 1234878710 // Telephone
#define ITEM_SEWING_KIT 1234880403 // Sewing Kit
#define ITEM_JACK_O_LANTERN_ANGRY 1242482355 // Jack O Lantern Angry
#define ITEM_CURSED_CAULDRON 1242522330 // Cursed Cauldron
#define ITEM_TIMED_EXPLOSIVE_CHARGE 1248356124 // Timed Explosive Charge
#define ITEM_SUNGLASSES_6 1258768145 // Sunglasses
#define ITEM_MIXING_TABLE 1259919256 // Mixing Table
#define ITEM_SMOKE_GRENADE 1263920163 // Smoke Grenade
#define ITEM_HAZMAT_SUIT 1266491000 // Hazmat Suit
#define ITEM_GREEN_INDUSTRIAL_WALL_LIGHT 1268178466 // Green Industrial Wall Light
#define ITEM_RED_BERRY 1272194103 // Red Berry
#define ITEM_WHEELBARROW_PIANO 1272430949 // Wheelbarrow Piano
#define ITEM_SPOILED_HUMAN_MEAT 1272768630 // Spoiled Human Meat
#define ITEM_WEAPON_RACK_DOUBLE_LIGHT 1277159544 // Weapon Rack Double Light
#define ITEM_XOR_SWITCH 1293102274 // XOR Switch
#define ITEM_HOMING_MISSILE 1296788329 // Homing Missile
#define ITEM_SMALL_NEON_SIGN 1305578813 // Small Neon Sign
#define ITEM_STORAGE_BARREL_VERTICAL 1307626005 // Storage Barrel Vertical
#define ITEM_WOOD_MIRROR_LARGE 1312679249 // Wood Mirror Large
#define ITEM_SKULL 1312843609 // Skull
#define ITEM_OX_MASK 1315082560 // Ox Mask
#define ITEM_MP5A4 1318558775 // MP5A4
#define ITEM_SMALL_LOOT_BAG 1319617282 // Small Loot Bag
#define ITEM_CHAMPAGNE_BOOMER 1324203999 // Champagne Boomer
#define ITEM_SALVAGED_SWORD 1326180354 // Salvaged Sword
#define ITEM_SHORT_ICE_WALL 1327005675 // Short Ice Wall
#define ITEM_LOW_QUALITY_VALVES 1330084809 // Low Quality Valves
#define ITEM_PUMPKIN_BASKET 1346158228 // Pumpkin Basket
#define ITEM_SPOILED_BEAR_MEAT 1348294923 // Spoiled Bear Meat
#define ITEM_JUNGLE_ROCK 1350707894 // Jungle Rock
#define ITEM_ARMORED_DOOR 1353298668 // Armored Door
#define ITEM_SNOW_MACHINE 1358643074 // Snow Machine
#define ITEM_MINECART_PLANTER 1361520181 // Minecart Planter
#define ITEM_BLUE_ID_TAG 1364514421 // Blue ID Tag
#define ITEM_GOLD_MIRROR_LARGE 1365234594 // Gold Mirror large
#define ITEM_LEATHER_GLOVES 1366282552 // Leather Gloves
#define ITEM_CORN 1367190888 // Corn
#define ITEM_TESLA_COIL 1371909803 // Tesla Coil
#define ITEM_WOODEN_BARRICADE_COVER 1373240771 // Wooden Barricade Cover
#define ITEM_PYTHON_REVOLVER 1373971859 // Python Revolver
#define ITEM_REAR_SEATS_VEHICLE_MODULE 1376065505 // Rear Seats Vehicle Module
#define ITEM_LEATHER 1381010055 // Leather
#define ITEM_BARBED_WOODEN_BARRICADE 1382263453 // Barbed Wooden Barricade
#define ITEM_SHEET_METAL_DOUBLE_DOOR 1390353317 // Sheet Metal Double Door
#define ITEM_BURNT_PORK 1391703481 // Burnt Pork
#define ITEM_RHIB 1394042569 // RHIB
#define ITEM_SUPPLY_SIGNAL 1397052267 // Supply Signal
#define ITEM_SADDLE_BAG 1400460850 // Saddle bag
#define ITEM_DUCT_TAPE 1401987718 // Duct Tape
#define ITEM_DOOR_CLOSER 1409529282 // Door Closer
#define ITEM_SUNFLOWER_SEED 1412103380 // Sunflower Seed
#define ITEM_FRIDGE 1413014235 // Fridge
#define ITEM_NOTE 1414245162 // Note
#define ITEM_ROSE 1414245519 // Rose
#define ITEM_ROPE 1414245522 // Rope
#define ITEM_HORSE_COSTUME 1420547167 // Horse Costume
#define ITEM_RAW_DEER_MEAT 1422530437 // Raw Deer Meat
#define ITEM_WATER_BUCKET 1424075905 // Water Bucket
#define ITEM_COCONUT_ARMOR_CHESTPLATE 1426097945 // Coconut Armor Chestplate
#define ITEM_MINICOPTER 1426574435 // Minicopter
#define ITEM_HOPPER 1428574144 // Hopper
#define ITEM_INDUSTRIAL_CRAFTER 1430085198 // Industrial Crafter
#define ITEM_HUNTING_BOW 1443579727 // Hunting Bow
#define ITEM_CHAINLINK_FENCE_GATE 1451568081 // Chainlink Fence Gate
#define ITEM_COOKING_WORKBENCH 1456143403 // Cooking Workbench
#define ITEM_WANTED_POSTER_4 1463862472 // Wanted Poster 4
#define ITEM_PORK_PIE 1467878256 // Pork Pie
#define ITEM_MUZZLE_BRAKE 1478091698 // Muzzle Brake
#define ITEM_BASIC_ORE_TEA 1480022580 // Basic Ore Tea
#define ITEM_RETRO_TOOL_CUPBOARD 1488606552 // Retro Tool Cupboard
#define ITEM_JACKHAMMER 1488979457 // Jackhammer
#define ITEM_PADDLE 1491189398 // Paddle
#define ITEM_MEDIUM_FRANKENSTEIN_TORSO 1491753484 // Medium Frankenstein Torso
#define ITEM_DISCORD_TROPHY 1494014226 // Discord Trophy
#define ITEM_POTATO_CLONE 1512054436 // Potato Clone
#define ITEM_HARVESTING_TEA 1516531815 // Harvesting Tea
#define ITEM_NETTING 1516985844 // Netting
#define ITEM_DOUBLE_SIGN_POST 1521286012 // Double Sign Post
#define ITEM_TARGETING_COMPUTER 1523195708 // Targeting Computer
#define ITEM_CASSETTE_SHORT 1523403414 // Cassette - Short
#define ITEM_WORKBENCH_LEVEL_1 1524187186 // Workbench Level 1
#define ITEM_CARVABLE_PUMPKIN 1524980732 // Carvable Pumpkin
#define ITEM_BUILDING_PLAN 1525520776 // Building Plan
#define ITEM_WHITE_BERRY_CLONE 1533551194 // White Berry Clone
#define ITEM_CHAIR 1534542921 // Chair
#define ITEM_COOKED_HUMAN_MEAT 1536610005 // Cooked Human Meat
#define ITEM_INDUSTRIAL_COMBINER 1538126328 // Industrial Combiner
#define ITEM_WOODEN_SPEAR 1540934679 // Wooden Spear
#define ITEM_SINGLE_SIGN_POST 1542290441 // Single Sign Post
#define ITEM_ASSAULT_RIFLE 1545779598 // Assault Rifle
#define ITEM_APPLE 1548091822 // Apple
#define ITEM_BLEACH 1553078977 // Bleach
#define ITEM_MOLOTOV_COCKTAIL 1556365900 // Molotov Cocktail
#define ITEM_SUNGLASSES_7 1557173737 // Sunglasses
#define ITEM_ENGINE_VEHICLE_MODULE 1559779253 // Engine Vehicle Module
#define ITEM_SINGLE_HORSE_SADDLE 1559915778 // Single Horse Saddle
#define ITEM_ABYSS_METAL_PICKAXE 1561022037 // Abyss Metal Pickaxe
#define ITEM_DIESEL_FUEL 1568388703 // Diesel Fuel
#define ITEM_HANDMADE_FISHING_ROD 1569882109 // Handmade Fishing Rod
#define ITEM_MINT_ID_TAG 1572152877 // Mint ID Tag
#define ITEM_FRANKENSTEIN_TABLE 1575635062 // Frankenstein Table
#define ITEM_HAZMAT_PLUSHY 1578317134 // Hazmat Plushy
#define ITEM_LARGE_PLANTER_BOX 1581210395 // Large Planter Box
#define ITEM_BOLT_ACTION_RIFLE 1588298435 // Bolt Action Rifle
#define ITEM_DRONE 1588492232 // Drone
#define ITEM_BLUE_JUMPSUIT 1601468620 // Blue Jumpsuit
#define ITEM_JAR_OF_HONEY 1601800933 // Jar of Honey
#define ITEM_STONE_SPEAR 1602646136 // Stone Spear
#define ITEM_CONFETTI_CANNON 1603174987 // Confetti Cannon
#define ITEM_WOODEN_SHIELD 1604837581 // Wooden Shield
#define ITEM_TANK_TOP 1608640313 // Tank Top
#define ITEM_HEAVY_FRANKENSTEIN_TORSO 1614528785 // Heavy Frankenstein Torso
#define ITEM_DIGITAL_CLOCK 1619039771 // Digital Clock
#define ITEM_OUTBREAK_SPRAYER 1621942085 // Outbreak Sprayer
#define ITEM_INDUSTRIAL_WALL_LIGHT 1623701499 // Industrial Wall Light
#define ITEM_SNOWMAN 1629293099 // Snowman
#define ITEM_INCENDIARY_ROCKET 1638322904 // Incendiary Rocket
#define ITEM_LARGE_ANIMATED_NEON_SIGN 1643667218 // Large Animated Neon Sign
#define ITEM_METAL_BARRICADE 1655650836 // Metal Barricade
#define ITEM_EMPTY_CAN_OF_BEANS 1655979682 // Empty Can Of Beans
#define ITEM_LANTERN 1658229558 // Lantern
#define ITEM_GAS_MASK 1659114910 // Gas Mask
#define ITEM_WOODEN_HORSE_ARMOR 1659447559 // Wooden Horse Armor
#define ITEM_YELLOW_BERRY 1660145984 // Yellow Berry
#define ITEM_COOKED_FISH 1668129151 // Cooked Fish
#define ITEM_SMALL_STOCKING 1668858301 // Small Stocking
#define ITEM_BEENIE_HAT 1675639563 // Beenie Hat
#define ITEM_BOOMERANG 1680793490 // Boomerang
#define ITEM_DECORATIVE_GINGERBREAD_MEN 1686524871 // Decorative Gingerbread Men
#define ITEM_LIGHT_UP_FRAME_SMALL 1691223771 // Light-Up Frame Small
#define ITEM_MODULAR_CAR_LIFT 1696050067 // Modular Car Lift
#define ITEM_LANDSCAPE_PHOTO_FRAME 1697996440 // Landscape Photo Frame
#define ITEM_BONE_CLUB 1711033574 // Bone Club
#define ITEM_HV_5_56_RIFLE_AMMO 1712070256 // HV 5.56 Rifle Ammo
#define ITEM_PURE_MAX_HEALTH_TEA 1712261904 // Pure Max Health Tea
#define ITEM_CANDLE_HAT 1714496074 // Candle Hat
#define ITEM_BALLISTA 1714509152 // Ballista
#define ITEM_BONE_FRAGMENTS 1719978075 // Bone Fragments
#define ITEM_HIDE_PANTS 1722154847 // Hide Pants
#define ITEM_TREE_LIGHTS 1723747470 // Tree Lights
#define ITEM_WOODEN_DOOR 1729120840 // Wooden Door
#define ITEM_PURE_ORE_TEA 1729374708 // Pure Ore Tea
#define ITEM_PORTRAIT_PHOTO_FRAME 1729712564 // Portrait Photo Frame
#define ITEM_DISCO_FLOOR_2 1735402444 // Disco Floor
#define ITEM_BLUE_BOOMER 1744298439 // Blue Boomer
#define ITEM_BONE_ARMOR 1746956556 // Bone Armor
#define ITEM_HOODIE 1751045826 // Hoodie
#define ITEM_SILVER_EGG 1757265204 // Silver Egg
#define ITEM_TEAL 1758333838 // Teal
#define ITEM_GREEN_ID_TAG 1762167092 // Green ID Tag
#define ITEM_TOMAHA_SNOWMOBILE 1768112091 // Tomaha Snowmobile
#define ITEM_WOOD_FRAME_STANDING 1769475390 // Wood Frame Standing
#define ITEM_WORM 1770475779 // Worm
#define ITEM_GENERIC_VEHICLE_CHASSIS 1770744540 // Generic vehicle chassis
#define ITEM_BLACK_BERRY 1771755747 // Black Berry
#define ITEM_BLOOD 1776460938 // Blood
#define ITEM_CACTUS_FLESH 1783512007 // Cactus Flesh
#define ITEM_PARACHUTE_DEPLOYED 1784005657 // Parachute (Deployed)
#define ITEM_SOUSAPHONE 1784406797 // Sousaphone
#define ITEM_FRONTIER_MIRROR_STANDING 1787198294 // Frontier Mirror Standing
#define ITEM_CANDY_CANE_CLUB 1789825282 // Candy Cane Club
#define ITEM_CUSTOM_SMG 1796682209 // Custom SMG
#define ITEM_GARRY_S_MOD_TOOL_GUN 1803831286 // Garry's Mod Tool Gun
#define ITEM_RADIOACTIVE_WATER 1811780502 // Radioactive Water
#define ITEM_BONE_KNIFE 1814288539 // Bone Knife
#define ITEM_SKY_LANTERN 1819863051 // Sky Lantern
#define ITEM_BURNT_WOLF_MEAT 1827479659 // Burnt Wolf Meat
#define ITEM_SCATTERSHOT 1831249347 // Scattershot
#define ITEM_CABLE_TUNNEL 1835946060 // Cable Tunnel
#define ITEM_ABOVE_GROUND_POOL 1840570710 // Above Ground Pool
#define ITEM_BEANCAN_GRENADE 1840822026 // Beancan Grenade
#define ITEM_ABYSS_TORCH 1846605708 // Abyss Torch
#define ITEM_SMALL_GENERATOR 1849887541 // Small Generator
#define ITEM_ROAD_SIGN_KILT 1850456855 // Road Sign Kilt
#define ITEM_EGG_BASKET 1856217390 // Egg Basket
#define ITEM_EGG 1858828593 // Egg
#define ITEM_DRACULA_MASK 1865253052 // Dracula Mask
#define ITEM_MOTORBIKE_WITH_SIDECAR 1869224826 // Motorbike With Sidecar
#define ITEM_COCONUT_ARMOR_GLOVES 1873004466 // Coconut Armor Gloves
#define ITEM_COOKED_BEAR_MEAT 1873897110 // Cooked Bear Meat
#define ITEM_ARMORED_COCKPIT_VEHICLE_MODULE 1874610722 // Armored Cockpit Vehicle Module
#define ITEM_BURLAP_HEADWRAP 1877339384 // Burlap Headwrap
#define ITEM_ROWBOAT 1878053256 // Rowboat
#define ITEM_METAL_BLADE 1882709339 // Metal Blade
#define ITEM_LOW_QUALITY_PISTONS 1883981798 // Low Quality Pistons
#define ITEM_HIGH_QUALITY_PISTONS 1883981800 // High Quality Pistons
#define ITEM_MEDIUM_QUALITY_PISTONS 1883981801 // Medium Quality Pistons
#define ITEM_SPOOKY_SPEAKER 1885488976 // Spooky Speaker
#define ITEM_DISCO_BALL 1895235349 // Disco Ball
#define ITEM_PUMPKIN_PLANT_CLONE 1898094925 // Pumpkin Plant Clone
#define ITEM_MEDIUM_LOOT_BAG 1899610628 // Medium Loot Bag
#define ITEM_SMALL_PLANTER_BOX 1903654061 // Small Planter Box
#define ITEM_PURE_RAD_REMOVAL_TEA 1905387657 // Pure Rad. Removal Tea
#define ITEM_BLACK_BERRY_SEED 1911552868 // Black Berry Seed
#define ITEM_PROTOTYPE_17 1914691295 // Prototype 17
#define ITEM_LIGHT_UP_MIRROR_STANDING 1916016738 // Light-Up Mirror Standing
#define ITEM_BURNT_HORSE_MEAT 1917703890 // Burnt Horse Meat
#define ITEM_SPOILED_PORK_MEAT 1925646349 // Spoiled Pork Meat
#define ITEM_BLACK_RASPBERRIES 1931713481 // Black Raspberries
#define ITEM_FRONTIER_HATCHET 1937380239 // Frontier Hatchet
#define ITEM_CAMP_FIRE 1946219319 // Camp Fire
#define ITEM_LADDER_HATCH 1948067030 // Ladder Hatch
#define ITEM_LIGHT_UP_FRAME_STANDING 1950013766 // Light-Up Frame Standing
#define ITEM_SALVAGED_SHELVES 1950721418 // Salvaged Shelves
#define ITEM_SWITCH 1951603367 // Switch
#define ITEM_NAILGUN 1953903201 // Nailgun
#define ITEM_CROSSBOW 1965232394 // Crossbow
#define ITEM_BIRTHDAY_CAKE 1973165031 // Birthday Cake
#define ITEM_BURNT_CHICKEN 1973684065 // Burnt Chicken
#define ITEM_FRONTIER_BOLTS_SINGLE_ITEM_RACK 1973949960 // Frontier Bolts Single Item Rack
#define ITEM_SURVEY_CHARGE 1975934948 // Survey Charge
#define ITEM_FLOOR_TRIANGLE_GRILL 1983621560 // Floor triangle grill
#define ITEM_HIGH_QUALITY_HORSE_SHOES 1989785143 // High Quality Horse Shoes
#define ITEM_TRIKE 1991794121 // Trike
#define ITEM_BURLAP_TROUSERS 1992974553 // Burlap Trousers
#define ITEM_EXTENDED_MAGAZINE 2005491391 // Extended Magazine
#define ITEM_CHRISTMAS_DOOR_WREATH 2009734114 // Christmas Door Wreath
#define ITEM_TARP 2019042823 // Tarp
#define ITEM_ADVANCED_RAD_REMOVAL_TEA 2021351233 // Advanced Rad. Removal Tea
#define ITEM_MEDIUM_RECHARGEABLE_BATTERY 2023888403 // Medium Rechargeable Battery
#define ITEM_PURE_SCRAP_TEA 2024467711 // Pure Scrap Tea
#define ITEM_SCATTER_DART 2036395619 // Scatter Dart
#define ITEM_BEAR_PIE 2039177180 // Bear Pie
#define ITEM_COMBAT_KNIFE 2040726127 // Combat Knife
#define ITEM_TRIANGLE_LADDER_HATCH 2041899972 // Triangle Ladder Hatch
#define ITEM_LEAD_ARMOR_INSERT 2047789913 // Lead Armor Insert
#define ITEM_WOLF_SKULL 2048317869 // Wolf Skull
#define ITEM_INNER_TUBE_3 2052270186 // Inner Tube
#define ITEM_FACTORY_DOOR 2054391128 // Factory Door
#define ITEM_JUNGLE_RELIC_ASSAULT_RIFLE 2054929933 // Jungle Relic Assault Rifle
#define ITEM_FRONTIER_MIRROR_MEDIUM 2055695285 // Frontier Mirror Medium
#define ITEM_ADVANCED_ORE_TEA 2063916636 // Advanced Ore Tea
#define ITEM_SMALL_BACKPACK 2068884361 // Small Backpack
#define ITEM_LARGE_BANNER_ON_POLE 2070189026 // Large Banner on pole
#define ITEM_HANDMADE_SMG 2083256995 // Handmade SMG
#define ITEM_SEARCH_LIGHT 2087678962 // Search Light
#define ITEM_LARGE_SOLAR_PANEL 2090395347 // Large Solar Panel
#define ITEM_AUDIO_ALARM 2100007442 // Audio Alarm
#define ITEM_STROBE_LIGHT 2104517339 // Strobe Light
#define ITEM_DECORATIVE_TINSEL 2106561762 // Decorative Tinsel
#define ITEM_WATER_PURIFIER 2114754781 // Water Purifier
#define ITEM_GOLD_MIRROR_STANDING 2120241887 // Gold Mirror Standing
#define ITEM_SANTA_BEARD 2126889441 // Santa Beard
#define ITEM_RED_BERRY_CLONE 2133269020 // Red Berry Clone
#define ITEM_HIGH_EXTERNAL_FRONTIER_GATE 2137338174 // High External Frontier Gate

// Function declarations

#ifdef __cplusplus
}
#endif

#endif
