# 42-push_swap

## 프로젝트 개요
`42-push_swap` 프로젝트는 42 서울의 push_swap 프로젝트입니다. 이 프로젝트의 목표는 주어진 정수 배열을 정렬하는 알고리즘을 구현하는 것입니다. 프로젝트에는 `push_swap`과 `checker`라는 두 가지 프로그램이 포함되어 있습니다.

## 주요 기능
- `push_swap`: 정렬 알고리즘을 구현한 프로그램입니다. 주어진 숫자 배열을 정렬하는 알고리즘을 실행합니다.
- `checker`: 정렬된 배열을 확인하는 프로그램입니다. `push_swap` 알고리즘으로 정렬된 배열을 확인하여 정렬 여부를 검증합니다.

## 실행 방법
1. `git clone` 명령어를 사용하여 프로젝트를 로컬 환경으로 복제합니다.
2. 터미널에서 `make` 명령어를 실행하여 프로그램을 컴파일합니다.
3. `push_swap` 프로그램을 실행하여 정렬 알고리즘을 수행합니다. 예시: `./push_swap 3 2 1`
4. `checker` 프로그램을 실행하여 정렬된 배열을 확인합니다. 예시: `./push_swap 3 2 1 | ./checker 3 2 1`

## 주요 작업과 명령어
다음은 `push_swap` 프로그램에서 사용할 수 있는 주요 작업과 명령어입니다:

- `sa` (swap a): 스택 a 맨 위의 가장 처음 두 요소를 바꿉니다.
- `sb` (swap b): 스택 b 맨 위의 가장 처음 두 요소를 바꿉니다.
- `ss`: `sa`와 `sb`를 동시에 수행합니다.
- `pa` (push a): 스택 b 맨 위의 첫 번째 요소를 가져와 스택 a 맨 위에 놓습니다.
- `pb` (push b): 스택 a 맨 위의 첫 번째 요소를 가져와 스택 b 맨 위에 놓습니다.
- `ra` (rotate a): 스택 a의 요소들의 위치를 한 칸씩 앞당깁니다.
- `rb` (rotate b): 스택 b의 요소들의 위치를 한 칸씩 앞당깁니다.
- `rr`: `ra`와 `rb`를 동시에 수행합니다.
- `rra` (reverse rotate a): 스택 a의 요소들의 위치를 한 칸씩 뒤로 이동합니다.
- `rrb` (reverse rotate b): 스택 b의 요소들의 위치를 한 칸씩 뒤로 이동합니다.
- `rrr`: `rra`와 `rrb`를 동시에 수행합니다.

## 개발 과정 및 회고
해당 프로젝트는 제한된 명령어의 횟수 이내로 입력받은 숫자를 정렬해야합니다.
때문에 많은 숫자가 입력되더라도 시간복잡도 측면에서 효율적일 수 있도록 병합 정렬 알고리즘을 사용하여 구현하였습니다.
개발 과정 및 회고[https://velog.io/@hyuntall/42-Seoul-Pushswap-%EA%B3%BC%EC%A0%9C-%EC%A0%95%EB%A6%AC-2]

## 실행 화면 예시

### push_swap

make

./push_swap 정렬되지 않고, 중복되지 않은 숫자를 매개변수로 입력합니다.

![image](https://github.com/hyuntall/42-push_swap/assets/71054445/5d96b806-0b61-43b2-85be-77aa2cdbb383)

### checker

make bonus

./checker 정렬되지 않고, 중복되지 않은 숫자를 매개변수로 입력합니다.
이후 임의의 커맨드를 입력합니다.

#### 알맞은 명령어를 입력했을 때의 모습

![image](https://github.com/hyuntall/42-push_swap/assets/71054445/dafa60f6-87a2-4d5d-8550-f07349e963aa)

#### 알맞지 않은 명령어를 입력했을 때의 모습

![image](https://github.com/hyuntall/42-push_swap/assets/71054445/228685e4-9d9e-47d2-a8be-9ec54fdcfd98)

## 정렬된 모습
![image](https://github.com/hyuntall/42-push_swap/assets/71054445/e1c82e0a-6269-402b-beb4-2a78a8a3ab9b)
push-swap 비주얼라이저를 통해 정렬 과정 및 정렬 결과를 시각화한 모습입니다.
