# Computer-Graphics

### HW1
컴퓨터 그래픽스에서는 물체의 위치(position)와 이동(translation)/회전(rotation)/확대축소(scaling)와 같은 변환(transformation)을 표현하기 위해, 벡터와 행렬 연산이 필수적이다. 본 과제에서는 OpenGL Mathematics(GLM)을 이용해 벡터, 행렬, 변환 예제를 실습하는 것을 목표로 한다.

### HW2
본 과제에서는 버퍼 객체를 이용해 물체를 그리는 간단한 모던 OpenGL 프로그램을 작성한다. 모던 OpenGL의 정점 버퍼 객체 (vertex buffer object, VBO)와 인덱스 버퍼 개체 (index buffer object, IBO)를 사용하는 예제를 실습하여 OpenGL 버퍼 객체를 활용한 모델 데이터의 표현법을 익한다.

### HW3
본 과제에서는 사용자의 입력에 반응하는 그래픽스 프로그램을 작성한다. GLFW의 콜백함수(callback function)와 ImGui를 사용하여 사용자 입력을 통해 물체의 위치, 크기, 회전을 바꾸는 방법을 익힌다.

### HW4
본 과제에서는 사용자의 입력에 반응하여 카메라를 조작하는 그래픽스 프로그램을 작성한다. GLFW의 콜백 함수와 ImGui를 사용하여 사용자 입력을 통해 카메라의 위치, 회전, 시야각을 바꾸는 방법을 익힌다.

### HW5
본 과제에서는 Open Asset Import Library (Assimp)를 사용하여 여러 개의 모델을 불러와 여러 시점의 카메라로 렌더하는 프로그램을 작성한다.

### HW6
본 과제에서는 Phong reflection model을 이용해 per-pixel 단위로 물체를 렌더링하는 프로그램을 작성한다. 프로그램 실행 중 각 물체의 쉐이딩 모드는 smooth shading이나 flat shading 중 하나로 선택할 수 있도록 한다. 