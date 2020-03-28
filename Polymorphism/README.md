# A text based Create-Your-Own game that uses object orientated programming.

# Derived Classes
## Warrior
Stores the warrior's allegiance as a string.

The warrior does not attack warriors that have the same allegiance.

The damage done by the warrior is the percentage of the warrior's health remaining (health / MAX_HEALTH) multiplied by the warrior's attack strength.

## Elf
Stores the elf's family name as a string.

The elf does not attack elf's from its own family.

The damage done by the elf is the percentage of the elf's health remaining (health / MAX_HEALTH) multiplied by the elf's attack strength.

## Wizard
Stores the wizard's rank as an int.

When a wizard attacks another wizard, the damage done is the wizard's attack strength multiplied by the ratio of the attacking wizard's rank over the defending wizard's rank.

The damage done to non-wizards is just the attack strength. The wizard's health is not taken into consideration.
