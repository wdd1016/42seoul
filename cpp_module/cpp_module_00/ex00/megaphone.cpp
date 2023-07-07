/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juyojeon <juyojeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 23:50:20 by juyojeon          #+#    #+#             */
/*   Updated: 2023/07/07 17:48:36 by juyojeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char* argv[]) {
	if (argc == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	} else {
		for (int i = 1; i < argc; i++) {
			for (int j = 0; argv[i][j]; j++) {
				argv[i][j] = std::toupper(argv[i][j]);
				/* 순회하면서 대문자 변환 */
			}
			std::cout << argv[i];
			/* 인자 1개씩 출력 */
		}
		std::cout << std::endl;
		/* 모두 출력하면 줄바꿈으로 마무리 */
	}
}
