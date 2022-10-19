// 키가 3개인 객체 myInfo - name, phoneNumber, samsung products
const myInfo = {
    name: 'jack',
    phoneNumber: '01012345678',
    'sumsung products': {
        buds: 'Galaxy Buds pro',
        galaxy: 'Galaxy s99'
    },
}

console.log(myInfo.name)
console.log(myInfo['name'])

// console.log(myInfo.'sumsung products') // 불가능
console.log(myInfo['sumsung products'])
console.log(myInfo['sumsung products'].galaxy)

// ===== 메서드 명 축약 =====
const obj = {
	greeting() {
		console,log('Hi!')
	}
}
// console.log(obj.name)
// console.log(obj.greeting())

// ===== 계산된 속성 =====
const key = 'country'
const value = ['한국', '미국', '일본', '중국']

const myObj = {
    [key]: value,
}
console.log(myObj)
console.log(myObj.country)

// ===== 구조 분해 할당 =====
const userInfo = {
	name: 'ssafy kim',
	userId: 'ssafyStudent1234',
	phone: '010-1234-5678',
	email: 'ssafy@ssafy.com'
}
const { name } = userInfo
const { userId } = userInfo
const { phoneNumber } = userInfo
const { email } = userInfo
// 여러개도 가능
// const { name,userId } = userInformation

// ===== Spread syntax =====
const obj1 = {b: 2, c: 3, d: 4}
const newObj = {a: 1, ...obj1, e: 5}

console.log(newObj)     // {a: 1, b: 2, c: 3, d: 4, e: 5}

// ===== JSON =====
const jsonData = {
    coffee: 'Americano',
    iceCream: 'Cookie and cream',
}
// 1. Object -> json
const objToJson = JSON.stringify(jsonData)

console.log(objToJson)          // {"coffee":"Americano","iceCream":"Cookie and cream"}
console.log(typeof objToJson)   // string

// 2. json -> Object
const jsonToObj = JSON.parse(objToJson)

console.log(jsonToObj)          // {coffee: 'Americano', iceCream: 'Cookie and cream'}
console.log(typeof jsonToObj)   // object
console.log(jsonToObj.coffee)   // Americano