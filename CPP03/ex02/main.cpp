/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migonzal <migonzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 16:13:58 by migonzal          #+#    #+#             */
/*   Updated: 2025/10/03 16:14:01 by migonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
	ClapTrap c("Clappy");
	ScavTrap s("Scavy");
	FragTrap f("Fraggy");

	c.attack("Scavy");
	s.takeDamage(0);
	s.attack("Fraggy");
	f.takeDamage(20);

	f.attack("Scavy");
	s.takeDamage(30);

	s.guardGate();
	f.highFivesGuys();

	FragTrap f2 = f;
	f2.attack("Clappy");

	return 0;
}