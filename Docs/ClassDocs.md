# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`Container`](#class_container) | 
`class `[`Container< T >`](#class_container_3_01_t_01_4) | [Container<T>](#class_container_3_01_t_01_4) is a circular data structure.
`class `[`CustomDelegate`](#class_custom_delegate) | 
`class `[`DimmerableLight`](#class_dimmerable_light) | specific [IoT](#class_io_t) implementation for [DimmerableLight](#class_dimmerable_light) devices
`class `[`InteractiveIot`](#class_interactive_iot) | 
`class `[`IoTBuilder`](#class_io_t_builder) | [IoTBuilder](#class_io_t_builder) this class is used to.
`class `[`Model::IoTContainer`](#class_model_1_1_io_t_container) | The [IoTContainer](#class_model_1_1_io_t_container) class.
`class `[`IoTFactoryDevice`](#class_io_t_factory_device) | [IoTBuilder](#class_io_t_builder) implementation as template.
`class `[`Container::Iterator`](#class_container_1_1_iterator) | 
`class `[`MainContent`](#class_main_content) | 
`class `[`MainWindow`](#class_main_window) | 
`class `[`Model`](#class_model) | 
`class `[`Container::Node`](#class_container_1_1_node) | 
`class `[`Shutter`](#class_shutter) | specific [IoT](#class_io_t) implementation for [Shutter](#class_shutter) devices
`class `[`Switch`](#class_switch) | specific [IoT](#class_io_t) implementation for [Switch](#class_switch) devices

# class `Container` {#class_container}

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`Container`](#class_container_1ab17ce1f67243b28abcd4c8113a72524c)`()` | [Container](#class_container).
`public  `[`Container`](#class_container_1a17d2440f122105579af08bc492722084)`(const `[`Container`](#class_container)`< T > & c)` | [Container](#class_container).
`public  `[`Container`](#class_container_1a7e51eb68e037156e7229200ec63b65b7)`(const `[`Container`](#class_container)`< T > * c)` | [Container](#class_container).
`public `[`Container`](#class_container)`< T > * `[`clone`](#class_container_1a041684cbea288d995c1c342142069f05)`() const` | clone
`public void `[`pushFront`](#class_container_1a19be7830195c001f3fb5a3e1addbaa36)`(const T & value)` | push_front
`public void `[`pushBack`](#class_container_1a0b87d11da4058763e5b399383468848e)`(const T & value)` | push_back
`public const `[`Iterator`](#class_container_1_1_iterator)` & `[`search`](#class_container_1a2a9f003c7f43da333555398a84ae5940)`(const T & value) const` | search
`public void `[`insert`](#class_container_1a53ef87dcf2d2da18007585edca3d7dbd)`(const int i,const T & value)` | insert
`public void `[`insertAfterIterator`](#class_container_1a9c52e2ed1d7660375ae366f5ab78b60b)`(const `[`Iterator`](#class_container_1_1_iterator)` & it,const T & value)` | insertAfterIterator
`public const T & `[`operator[]`](#class_container_1a659618cf2b30fab3521148372f6a850b)`(int index) const` | operator []
`public void `[`deleteElementAt`](#class_container_1ac7e1774b45c50514045b7bb50ea750f6)`(int i)` | deleteElementAt
`public void `[`deleteElementAt`](#class_container_1a524c0b5b6134e87991dc27b55bf267b0)`(const `[`Iterator`](#class_container_1_1_iterator)` & it)` | deleteElementAt
`public `[`Iterator`](#class_container_1_1_iterator)` * `[`getIterator`](#class_container_1a9513ffaac9c3de027da3552dd2f89c6e)`()` | getIterator
`public const `[`Iterator`](#class_container_1_1_iterator)` * `[`getConstIterator`](#class_container_1ab5bed05415f3b7d9488903b145b7ab48)`() const` | getConstInterator
`public const `[`Iterator`](#class_container_1_1_iterator)` * `[`getConstIteratorAt`](#class_container_1a4b05c6da35d09b8e5ada9b4242b5d5cc)`(int index) const` | getConstInteratorAt
`public `[`Iterator`](#class_container_1_1_iterator)` * `[`getIteratorAt`](#class_container_1a73d7a56505bc25aa3d500302e39fcb9f)`(int index)` | getIteratorAt
`public int `[`size`](#class_container_1aac6a50c28bdc7826afcc6b92337d0c43)`() const noexcept` | size
`public  `[`~Container`](#class_container_1a5b3440c3177017d2d6a190724e7078ec)`()` | 

## Members

#### `public  `[`Container`](#class_container_1ab17ce1f67243b28abcd4c8113a72524c)`()` {#class_container_1ab17ce1f67243b28abcd4c8113a72524c}

[Container](#class_container).

Base constructor

#### `public  `[`Container`](#class_container_1a17d2440f122105579af08bc492722084)`(const `[`Container`](#class_container)`< T > & c)` {#class_container_1a17d2440f122105579af08bc492722084}

[Container](#class_container).

Copy constructor does not perfom a deepcopy 
#### Parameters
* `c`

#### `public  `[`Container`](#class_container_1a7e51eb68e037156e7229200ec63b65b7)`(const `[`Container`](#class_container)`< T > * c)` {#class_container_1a7e51eb68e037156e7229200ec63b65b7}

[Container](#class_container).

Copy constructor does not perfom a deepcopy 
#### Parameters
* `c`

#### `public `[`Container`](#class_container)`< T > * `[`clone`](#class_container_1a041684cbea288d995c1c342142069f05)`() const` {#class_container_1a041684cbea288d995c1c342142069f05}

clone

clones the current [Container](#class_container) does perfom a deepcopy 
#### Returns

#### `public void `[`pushFront`](#class_container_1a19be7830195c001f3fb5a3e1addbaa36)`(const T & value)` {#class_container_1a19be7830195c001f3fb5a3e1addbaa36}

push_front

insert T in the front of the data structure 
#### Parameters
* `value`

#### `public void `[`pushBack`](#class_container_1a0b87d11da4058763e5b399383468848e)`(const T & value)` {#class_container_1a0b87d11da4058763e5b399383468848e}

push_back

insert T in the back of the data structure 
#### Parameters
* `value`

#### `public const `[`Iterator`](#class_container_1_1_iterator)` & `[`search`](#class_container_1a2a9f003c7f43da333555398a84ae5940)`(const T & value) const` {#class_container_1a2a9f003c7f43da333555398a84ae5940}

search

returns the iterator for the T wanted 
#### Parameters
* `value` 

#### Returns

#### `public void `[`insert`](#class_container_1a53ef87dcf2d2da18007585edca3d7dbd)`(const int i,const T & value)` {#class_container_1a53ef87dcf2d2da18007585edca3d7dbd}

insert

insert T in the i position 
#### Parameters
* `i` 

* `value`

#### `public void `[`insertAfterIterator`](#class_container_1a9c52e2ed1d7660375ae366f5ab78b60b)`(const `[`Iterator`](#class_container_1_1_iterator)` & it,const T & value)` {#class_container_1a9c52e2ed1d7660375ae366f5ab78b60b}

insertAfterIterator

insert T after the iterator 
#### Parameters
* `it`

#### `public const T & `[`operator[]`](#class_container_1a659618cf2b30fab3521148372f6a850b)`(int index) const` {#class_container_1a659618cf2b30fab3521148372f6a850b}

operator []

returns the content of the node in index position 
#### Parameters
* `index` 

#### Returns

#### `public void `[`deleteElementAt`](#class_container_1ac7e1774b45c50514045b7bb50ea750f6)`(int i)` {#class_container_1ac7e1774b45c50514045b7bb50ea750f6}

deleteElementAt

deletes the element at i position. if T is a pointer does not perfrom deep delete; 
#### Parameters
* `i`

#### `public void `[`deleteElementAt`](#class_container_1a524c0b5b6134e87991dc27b55bf267b0)`(const `[`Iterator`](#class_container_1_1_iterator)` & it)` {#class_container_1a524c0b5b6134e87991dc27b55bf267b0}

deleteElementAt

deletes the element at the iterator position if is valid. if T is a pointer does not perfrom deep delete; 
#### Parameters
* `it`

#### `public `[`Iterator`](#class_container_1_1_iterator)` * `[`getIterator`](#class_container_1a9513ffaac9c3de027da3552dd2f89c6e)`()` {#class_container_1a9513ffaac9c3de027da3552dd2f89c6e}

getIterator

returns the iterator at the start 
#### Returns

#### `public const `[`Iterator`](#class_container_1_1_iterator)` * `[`getConstIterator`](#class_container_1ab5bed05415f3b7d9488903b145b7ab48)`() const` {#class_container_1ab5bed05415f3b7d9488903b145b7ab48}

getConstInterator

returns the const iterator at the start 
#### Returns
const [Iterator](#class_container_1_1_iterator)

#### `public const `[`Iterator`](#class_container_1_1_iterator)` * `[`getConstIteratorAt`](#class_container_1a4b05c6da35d09b8e5ada9b4242b5d5cc)`(int index) const` {#class_container_1a4b05c6da35d09b8e5ada9b4242b5d5cc}

getConstInteratorAt

returns the const iterator at the index 
#### Parameters
* `index` 

#### Returns
const [Iterator](#class_container_1_1_iterator)

#### `public `[`Iterator`](#class_container_1_1_iterator)` * `[`getIteratorAt`](#class_container_1a73d7a56505bc25aa3d500302e39fcb9f)`(int index)` {#class_container_1a73d7a56505bc25aa3d500302e39fcb9f}

getIteratorAt

returns the iterator at the index position 
#### Parameters
* `index` 

#### Returns

#### `public int `[`size`](#class_container_1aac6a50c28bdc7826afcc6b92337d0c43)`() const noexcept` {#class_container_1aac6a50c28bdc7826afcc6b92337d0c43}

size

#### Returns

#### `public  `[`~Container`](#class_container_1a5b3440c3177017d2d6a190724e7078ec)`()` {#class_container_1a5b3440c3177017d2d6a190724e7078ec}

# class `Container< T >` {#class_container_3_01_t_01_4}

[Container<T>](#class_container_3_01_t_01_4) is a circular data structure.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `CustomDelegate` {#class_custom_delegate}

```
class CustomDelegate
  : public QStyledItemDelegate
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`CustomDelegate`](#class_custom_delegate_1a1db7b838956c4d612014028919fc89aa)`(QWidget * parent)` | 
`public void `[`paint`](#class_custom_delegate_1a195613e6ad25d033b35b81321d9681ea)`(QPainter * painter,const QStyleOptionViewItem & option,const QModelIndex & index) const` | paint

## Members

#### `public inline  `[`CustomDelegate`](#class_custom_delegate_1a1db7b838956c4d612014028919fc89aa)`(QWidget * parent)` {#class_custom_delegate_1a1db7b838956c4d612014028919fc89aa}

#### `public void `[`paint`](#class_custom_delegate_1a195613e6ad25d033b35b81321d9681ea)`(QPainter * painter,const QStyleOptionViewItem & option,const QModelIndex & index) const` {#class_custom_delegate_1a195613e6ad25d033b35b81321d9681ea}

paint

replace the default paint method centering the content for all the column in the thrid column the Json get formatted 
#### Parameters
* `painter` 

* `option` 

* `index`

# class `DimmerableLight` {#class_dimmerable_light}

```
class DimmerableLight
  : public IoT
  : public IoT
```  

specific [IoT](#class_io_t) implementation for [DimmerableLight](#class_dimmerable_light) devices

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`DimmerableLight`](#class_dimmerable_light_1add935b60ac435205ec347854aff0ede9)`(const std::string & fSerial,const std::string & fRoom,const std::string & fName)` | [DimmerableLight](#class_dimmerable_light).
`public  `[`DimmerableLight`](#class_dimmerable_light_1a98cc99fcee1fe348047baba357c2b05b)`(const QJsonDocument & initializer)` | [DimmerableLight](#class_dimmerable_light).
`public virtual const QJsonDocument & `[`getDeviceInstruction`](#class_dimmerable_light_1af62e84955485f0d0a8073f1fc7314b90)`() const` | getDeviceInstruction
`public virtual void `[`setDevice`](#class_dimmerable_light_1aafa22f4bada2ecbca917ef879c95824f)`(const QJsonDocument & instruction)` | setDevice
`public virtual `[`IoT`](#class_io_t)` * `[`clone`](#class_dimmerable_light_1ace70a035433bc16dbe11f139f1745b58)`() const` | clone

## Members

#### `public  `[`DimmerableLight`](#class_dimmerable_light_1add935b60ac435205ec347854aff0ede9)`(const std::string & fSerial,const std::string & fRoom,const std::string & fName)` {#class_dimmerable_light_1add935b60ac435205ec347854aff0ede9}

[DimmerableLight](#class_dimmerable_light).

Base constructor only serial is needed recalls [IoT](#class_io_t) base constructor with fClass = lClass

#### Parameters
* `fSerial` 

* `fRoom` 

* `fName`

#### `public  `[`DimmerableLight`](#class_dimmerable_light_1a98cc99fcee1fe348047baba357c2b05b)`(const QJsonDocument & initializer)` {#class_dimmerable_light_1a98cc99fcee1fe348047baba357c2b05b}

[DimmerableLight](#class_dimmerable_light).

Works like the other constructor saving all the data inside a QJsonDocument recalls [IoT](#class_io_t) base constructor with fClass = lClass

#### Parameters
* `initializer`

#### `public virtual const QJsonDocument & `[`getDeviceInstruction`](#class_dimmerable_light_1af62e84955485f0d0a8073f1fc7314b90)`() const` {#class_dimmerable_light_1af62e84955485f0d0a8073f1fc7314b90}

getDeviceInstruction

specific [DimmerableLight](#class_dimmerable_light) implementation of the virtual method IoT::instruction depends on the type of the [IoT](#class_io_t) device

#### Returns
const QJsonDocument& that contains the device instruction

#### `public virtual void `[`setDevice`](#class_dimmerable_light_1aafa22f4bada2ecbca917ef879c95824f)`(const QJsonDocument & instruction)` {#class_dimmerable_light_1aafa22f4bada2ecbca917ef879c95824f}

setDevice

specific [DimmerableLight](#class_dimmerable_light) implementation of the virtual method [IoT::setDevice()](#class_io_t_1ad5a9af49c5d4674ac845a36fba07ea30) depends on the type of the [IoT](#class_io_t) device

#### Parameters
* `instruction`

#### `public virtual `[`IoT`](#class_io_t)` * `[`clone`](#class_dimmerable_light_1ace70a035433bc16dbe11f139f1745b58)`() const` {#class_dimmerable_light_1ace70a035433bc16dbe11f139f1745b58}

clone

specific [DimmerableLight](#class_dimmerable_light) implementation of the virtual method [IoT::clone()](#class_io_t_1a8e2dd15b9eb0341576fdd3450649b8c5) depends on the type of the [IoT](#class_io_t) device

#### Returns
[IoT](#class_io_t) pointer with the cloned object

# class `InteractiveIot` {#class_interactive_iot}

```
class InteractiveIot
  : public QDialog
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`InteractiveIot`](#class_interactive_iot_1a5398c19017428530e13af8f483f9f23d)`(QString JsonRooms,QString eDevice,QWidget * parent)` | [InteractiveIot](#class_interactive_iot).
`public  `[`~InteractiveIot`](#class_interactive_iot_1a5eeb0f7ca26afb40286e86eeb5b9dfc5)`()` | 
`{signal} public void `[`newDevice`](#class_interactive_iot_1a9fcedb63483a37eb32ca877d570c54ad)`(QString device)` | 
`{signal} public void `[`closing`](#class_interactive_iot_1af1d7050ea51438559cca1f7526e6594c)`()` | 

## Members

#### `public  `[`InteractiveIot`](#class_interactive_iot_1a5398c19017428530e13af8f483f9f23d)`(QString JsonRooms,QString eDevice,QWidget * parent)` {#class_interactive_iot_1a5398c19017428530e13af8f483f9f23d}

[InteractiveIot](#class_interactive_iot).

The only constructor, requires the room list in json format if the eDevice string is provied and is an valid [IoT](#class_io_t) device the interface will be used for edit the current device

#### Parameters
* `JsonRooms` 

* `eDevice` 

* `parent`

#### `public  `[`~InteractiveIot`](#class_interactive_iot_1a5eeb0f7ca26afb40286e86eeb5b9dfc5)`()` {#class_interactive_iot_1a5eeb0f7ca26afb40286e86eeb5b9dfc5}

#### `{signal} public void `[`newDevice`](#class_interactive_iot_1a9fcedb63483a37eb32ca877d570c54ad)`(QString device)` {#class_interactive_iot_1a9fcedb63483a37eb32ca877d570c54ad}

#### `{signal} public void `[`closing`](#class_interactive_iot_1af1d7050ea51438559cca1f7526e6594c)`()` {#class_interactive_iot_1af1d7050ea51438559cca1f7526e6594c}

# class `IoTBuilder` {#class_io_t_builder}

[IoTBuilder](#class_io_t_builder) this class is used to.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`IoTBuilder`](#class_io_t_builder_1ac4f4cb3bf4bf90236b819334f7c295a2)`()` | [IoTBuilder](#class_io_t_builder).
`public virtual  `[`~IoTBuilder`](#class_io_t_builder_1ae86d5ed1281d074f33d1650de82390cc)`() = default` | default destructor
`protected `[`IoT`](#class_io_t)` * `[`fbuild`](#class_io_t_builder_1a8a2078e0d1d20234bf5ea88b04422a95)`(const QJsonDocument & device) const` | fbuild
`protected `[`IoT`](#class_io_t)` * `[`fbuild`](#class_io_t_builder_1a57b29c2bb89d0464f97513c4b38de871)`(const std::string & fSerial,const std::string & fRoom,const std::string & fName) const` | fbuild

## Members

#### `public  `[`IoTBuilder`](#class_io_t_builder_1ac4f4cb3bf4bf90236b819334f7c295a2)`()` {#class_io_t_builder_1ac4f4cb3bf4bf90236b819334f7c295a2}

[IoTBuilder](#class_io_t_builder).

default constructor that initialize the map if is not

#### `public virtual  `[`~IoTBuilder`](#class_io_t_builder_1ae86d5ed1281d074f33d1650de82390cc)`() = default` {#class_io_t_builder_1ae86d5ed1281d074f33d1650de82390cc}

default destructor

#### `protected `[`IoT`](#class_io_t)` * `[`fbuild`](#class_io_t_builder_1a8a2078e0d1d20234bf5ea88b04422a95)`(const QJsonDocument & device) const` {#class_io_t_builder_1a8a2078e0d1d20234bf5ea88b04422a95}

fbuild

virtual method that returns a new [IoT](#class_io_t) object

#### Parameters
* `device` 

#### Returns
new IoTdevice

#### `protected `[`IoT`](#class_io_t)` * `[`fbuild`](#class_io_t_builder_1a57b29c2bb89d0464f97513c4b38de871)`(const std::string & fSerial,const std::string & fRoom,const std::string & fName) const` {#class_io_t_builder_1a57b29c2bb89d0464f97513c4b38de871}

fbuild

virtual method that returns a new [IoT](#class_io_t) object

#### Parameters
* `fSerial` 

* `fRoom` 

* `fName` 

#### Returns
new IoTdevice

# class `Model::IoTContainer` {#class_model_1_1_io_t_container}

```
class Model::IoTContainer
  : public Container< IoT * >
```  

The [IoTContainer](#class_model_1_1_io_t_container) class.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`IoTContainer`](#class_model_1_1_io_t_container_1ab22294b8f6cfe435aa1c5eda7080df6d)`()` | 
`public void `[`loadFromJson`](#class_model_1_1_io_t_container_1a6d4781427c994caef46ed8835b522387)`(const std::string & dev)` | 
`public std::string `[`serialize`](#class_model_1_1_io_t_container_1aceeeb99211f691bf073ebd14c2a7989b)`() const` | 
`public `[`Iterator`](#class_container_1a9830fc407400559db7e7783cc10a9394)` `[`searchName`](#class_model_1_1_io_t_container_1ab200c210465f845d241bc44e5fc2ab74)`(std::string name) const` | 
`public `[`Iterator`](#class_container_1a9830fc407400559db7e7783cc10a9394)` `[`searchSerial`](#class_model_1_1_io_t_container_1adb0625460a689769a7cf15b842a45285)`(std::string serial) const` | 
`public std::string `[`getDevicesForAttribute`](#class_model_1_1_io_t_container_1a67cc31d9d603d8cbc4b301a9a25eede6)`(std::string attribute) const` | 

## Members

#### `public  `[`IoTContainer`](#class_model_1_1_io_t_container_1ab22294b8f6cfe435aa1c5eda7080df6d)`()` {#class_model_1_1_io_t_container_1ab22294b8f6cfe435aa1c5eda7080df6d}

#### `public void `[`loadFromJson`](#class_model_1_1_io_t_container_1a6d4781427c994caef46ed8835b522387)`(const std::string & dev)` {#class_model_1_1_io_t_container_1a6d4781427c994caef46ed8835b522387}

#### `public std::string `[`serialize`](#class_model_1_1_io_t_container_1aceeeb99211f691bf073ebd14c2a7989b)`() const` {#class_model_1_1_io_t_container_1aceeeb99211f691bf073ebd14c2a7989b}

#### `public `[`Iterator`](#class_container_1a9830fc407400559db7e7783cc10a9394)` `[`searchName`](#class_model_1_1_io_t_container_1ab200c210465f845d241bc44e5fc2ab74)`(std::string name) const` {#class_model_1_1_io_t_container_1ab200c210465f845d241bc44e5fc2ab74}

#### `public `[`Iterator`](#class_container_1a9830fc407400559db7e7783cc10a9394)` `[`searchSerial`](#class_model_1_1_io_t_container_1adb0625460a689769a7cf15b842a45285)`(std::string serial) const` {#class_model_1_1_io_t_container_1adb0625460a689769a7cf15b842a45285}

#### `public std::string `[`getDevicesForAttribute`](#class_model_1_1_io_t_container_1a67cc31d9d603d8cbc4b301a9a25eede6)`(std::string attribute) const` {#class_model_1_1_io_t_container_1a67cc31d9d603d8cbc4b301a9a25eede6}

# class `IoTFactoryDevice` {#class_io_t_factory_device}

```
class IoTFactoryDevice
  : public IoTBuilder
  : public IoTBuilder
```  

[IoTBuilder](#class_io_t_builder) implementation as template.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`IoTFactoryDevice`](#class_io_t_factory_device_1ab7f72d8174ee2355e5ee5cd8e85b92a6)`(const std::string & name)` | [IoTFactoryDevice](#class_io_t_factory_device).
`public  `[`~IoTFactoryDevice`](#class_io_t_factory_device_1a5845e0c48fa79972892a2cdad3eed5b1)`() = default` | 
`protected inline virtual `[`IoT`](#class_io_t)` * `[`fbuild`](#class_io_t_factory_device_1a46917cff41fa0e3107cf701b6570705e)`(const QJsonDocument & device) const` | fbuild
`protected inline virtual `[`IoT`](#class_io_t)` * `[`fbuild`](#class_io_t_factory_device_1a4c0f159d9d9a0be1218c4ccb193af497)`(const std::string & fSerial,const std::string & fRoom,const std::string & fName) const` | fbuild

## Members

#### `public inline  `[`IoTFactoryDevice`](#class_io_t_factory_device_1ab7f72d8174ee2355e5ee5cd8e85b92a6)`(const std::string & name)` {#class_io_t_factory_device_1ab7f72d8174ee2355e5ee5cd8e85b92a6}

[IoTFactoryDevice](#class_io_t_factory_device).

#### Parameters
* `name`

#### `public  `[`~IoTFactoryDevice`](#class_io_t_factory_device_1a5845e0c48fa79972892a2cdad3eed5b1)`() = default` {#class_io_t_factory_device_1a5845e0c48fa79972892a2cdad3eed5b1}

#### `protected inline virtual `[`IoT`](#class_io_t)` * `[`fbuild`](#class_io_t_factory_device_1a46917cff41fa0e3107cf701b6570705e)`(const QJsonDocument & device) const` {#class_io_t_factory_device_1a46917cff41fa0e3107cf701b6570705e}

fbuild

#### Parameters
* `device` 

#### Returns

#### `protected inline virtual `[`IoT`](#class_io_t)` * `[`fbuild`](#class_io_t_factory_device_1a4c0f159d9d9a0be1218c4ccb193af497)`(const std::string & fSerial,const std::string & fRoom,const std::string & fName) const` {#class_io_t_factory_device_1a4c0f159d9d9a0be1218c4ccb193af497}

fbuild

#### Parameters
* `fSerial` 

* `fRoom` 

* `fName` 

#### Returns

# class `Container::Iterator` {#class_container_1_1_iterator}

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`Iterator`](#class_container_1_1_iterator_1a68629c503cc0a82ba42320c3e405bb70)`()` | [Iterator](#class_container_1_1_iterator).
`public  `[`Iterator`](#class_container_1_1_iterator_1a120efa4e666d2708c5380901f873ffd5)`(const `[`Iterator`](#class_container_1_1_iterator)` & e)` | [Iterator](#class_container_1_1_iterator).
`public  `[`Iterator`](#class_container_1_1_iterator_1a508f2237dd2d95180c9206c7bded4e65)`(const `[`Iterator`](#class_container_1_1_iterator)` * e)` | 
`public void `[`operator--`](#class_container_1_1_iterator_1af97abb53ea7da856697a517591faa104)`(int) const` | operator
`public void `[`operator++`](#class_container_1_1_iterator_1a4db9bf1331603c37b76c8065dbd162bb)`(int) const` | operator ++
`public const T & `[`operator *`](#class_container_1_1_iterator_1acda37f566433d15741298897ae716fd8)`() const` | operator *
`public const T & `[`getData`](#class_container_1_1_iterator_1a0abb496138b846be6bc950293138511e)`() const` | getData
`public void `[`operator=`](#class_container_1_1_iterator_1aae8f82bc2df09e26039af809a2c4c0e1)`(const T * data)` | operator =
`public bool `[`operator==`](#class_container_1_1_iterator_1a29784dbdcc27d7531b2eb18abd4be04e)`(const `[`Iterator`](#class_container_1_1_iterator)` & it) const` | operator ==
`public bool `[`operator==`](#class_container_1_1_iterator_1a8a54cc9f5d64870c0f84ed0fed8c7c20)`(const T * v) const` | operator ==
`public bool `[`operator!=`](#class_container_1_1_iterator_1a6ba2d1b65237b00cbb3978c746612ccb)`(const T * v) const` | operator !=

## Members

#### `public  `[`Iterator`](#class_container_1_1_iterator_1a68629c503cc0a82ba42320c3e405bb70)`()` {#class_container_1_1_iterator_1a68629c503cc0a82ba42320c3e405bb70}

[Iterator](#class_container_1_1_iterator).

Base constructor

#### `public  `[`Iterator`](#class_container_1_1_iterator_1a120efa4e666d2708c5380901f873ffd5)`(const `[`Iterator`](#class_container_1_1_iterator)` & e)` {#class_container_1_1_iterator_1a120efa4e666d2708c5380901f873ffd5}

[Iterator](#class_container_1_1_iterator).

Copy constructors

#### Parameters
* `e`

#### `public  `[`Iterator`](#class_container_1_1_iterator_1a508f2237dd2d95180c9206c7bded4e65)`(const `[`Iterator`](#class_container_1_1_iterator)` * e)` {#class_container_1_1_iterator_1a508f2237dd2d95180c9206c7bded4e65}

#### `public void `[`operator--`](#class_container_1_1_iterator_1af97abb53ea7da856697a517591faa104)`(int) const` {#class_container_1_1_iterator_1af97abb53ea7da856697a517591faa104}

operator

moves the iterator backwards

#### `public void `[`operator++`](#class_container_1_1_iterator_1a4db9bf1331603c37b76c8065dbd162bb)`(int) const` {#class_container_1_1_iterator_1a4db9bf1331603c37b76c8065dbd162bb}

operator ++

moves the iterator forward

#### `public const T & `[`operator *`](#class_container_1_1_iterator_1acda37f566433d15741298897ae716fd8)`() const` {#class_container_1_1_iterator_1acda37f566433d15741298897ae716fd8}

operator *

dereference the content of Node T 
#### Returns
T

#### `public const T & `[`getData`](#class_container_1_1_iterator_1a0abb496138b846be6bc950293138511e)`() const` {#class_container_1_1_iterator_1a0abb496138b846be6bc950293138511e}

getData

returns the content of Node 
#### Returns
T

#### `public void `[`operator=`](#class_container_1_1_iterator_1aae8f82bc2df09e26039af809a2c4c0e1)`(const T * data)` {#class_container_1_1_iterator_1aae8f82bc2df09e26039af809a2c4c0e1}

operator =

replace the content of node 
#### Parameters
* `data`

#### `public bool `[`operator==`](#class_container_1_1_iterator_1a29784dbdcc27d7531b2eb18abd4be04e)`(const `[`Iterator`](#class_container_1_1_iterator)` & it) const` {#class_container_1_1_iterator_1a29784dbdcc27d7531b2eb18abd4be04e}

operator ==

compares the current node content iterator with the one in argument 
#### Parameters
* `it` 

#### Returns

#### `public bool `[`operator==`](#class_container_1_1_iterator_1a8a54cc9f5d64870c0f84ed0fed8c7c20)`(const T * v) const` {#class_container_1_1_iterator_1a8a54cc9f5d64870c0f84ed0fed8c7c20}

operator ==

compares the current node content iterator with the one in argument 
#### Parameters
* `v` 

#### Returns

#### `public bool `[`operator!=`](#class_container_1_1_iterator_1a6ba2d1b65237b00cbb3978c746612ccb)`(const T * v) const` {#class_container_1_1_iterator_1a6ba2d1b65237b00cbb3978c746612ccb}

operator !=

compares the current node content iterator with the one in argument 
#### Parameters
* `v` 

#### Returns

# class `MainContent` {#class_main_content}

```
class MainContent
  : public QTabWidget
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  explicit `[`MainContent`](#class_main_content_1a91b3adce9ff737b06234eac931e1d94b)`(`[`QModel`](#class_q_model)` * eData,QWidget * parent)` | [MainContent](#class_main_content).
`public  `[`~MainContent`](#class_main_content_1af96ea732d30fb56c6295fa342015af3e)`()` | 
`public void `[`load`](#class_main_content_1a12c3acc7b2e0859593bff84ccf72e53e)`(QString filepath)` | load
`public void `[`save`](#class_main_content_1a4946c215b08b494174ed316da8e7a25f)`(QString filepath)` | save
`public int `[`size`](#class_main_content_1a24d13f0eb4c95e1a31545f9f373b140e)`()` | size
`{signal} public void `[`selectionChanged`](#class_main_content_1a259158107ca94a003e3981bfadf25032)`(const QItemSelection & selected)` | 
`{signal} public void `[`update`](#class_main_content_1ac9bb8c3e1525827cde315a3592977cb3)`()` | 
`{slot} public void `[`showEditOrAddEntryDialog`](#class_main_content_1adcb44ddace5c7d16065e250d92500734)`(QString device)` | showEditOrAddEntryDialog
`{slot} public void `[`showAddEntryDialog`](#class_main_content_1acca16b6749c6a285a95ced8e07dd37f9)`()` | showAddEntryDialog
`{slot} public void `[`addEntry`](#class_main_content_1ad017995228905192aae4b87fed88fbf0)`(QString device)` | addEntry
`{slot} public void `[`editEntry`](#class_main_content_1adaa870ab815c28f296261cec43080cbb)`(QString device)` | editEntry
`{slot} public void `[`removeEntry`](#class_main_content_1a642b899032127df2deeba5743e45b9b5)`()` | removeEntry
`{slot} public void `[`editSelectedRow`](#class_main_content_1aa5de41aec3cac3585e37d137a1099640)`()` | editSelectedRow

## Members

#### `public  explicit `[`MainContent`](#class_main_content_1a91b3adce9ff737b06234eac931e1d94b)`(`[`QModel`](#class_q_model)` * eData,QWidget * parent)` {#class_main_content_1a91b3adce9ff737b06234eac931e1d94b}

[MainContent](#class_main_content).

Constructor that require the [QModel](#class_q_model)
#### Parameters
* `eData` 

* `parent`

#### `public  `[`~MainContent`](#class_main_content_1af96ea732d30fb56c6295fa342015af3e)`()` {#class_main_content_1af96ea732d30fb56c6295fa342015af3e}

#### `public void `[`load`](#class_main_content_1a12c3acc7b2e0859593bff84ccf72e53e)`(QString filepath)` {#class_main_content_1a12c3acc7b2e0859593bff84ccf72e53e}

load

load the file in the filepath 
#### Parameters
* `filepath`

#### `public void `[`save`](#class_main_content_1a4946c215b08b494174ed316da8e7a25f)`(QString filepath)` {#class_main_content_1a4946c215b08b494174ed316da8e7a25f}

save

save the file in the filepath 
#### Parameters
* `filepath`

#### `public int `[`size`](#class_main_content_1a24d13f0eb4c95e1a31545f9f373b140e)`()` {#class_main_content_1a24d13f0eb4c95e1a31545f9f373b140e}

size

#### Returns

#### `{signal} public void `[`selectionChanged`](#class_main_content_1a259158107ca94a003e3981bfadf25032)`(const QItemSelection & selected)` {#class_main_content_1a259158107ca94a003e3981bfadf25032}

#### `{signal} public void `[`update`](#class_main_content_1ac9bb8c3e1525827cde315a3592977cb3)`()` {#class_main_content_1ac9bb8c3e1525827cde315a3592977cb3}

#### `{slot} public void `[`showEditOrAddEntryDialog`](#class_main_content_1adcb44ddace5c7d16065e250d92500734)`(QString device)` {#class_main_content_1adcb44ddace5c7d16065e250d92500734}

showEditOrAddEntryDialog

shows the interactiveiot interface, the string is requred to edit the [IoT](#class_io_t) device 
#### Parameters
* `device`

#### `{slot} public void `[`showAddEntryDialog`](#class_main_content_1acca16b6749c6a285a95ced8e07dd37f9)`()` {#class_main_content_1acca16b6749c6a285a95ced8e07dd37f9}

showAddEntryDialog

show the interface to add an [IoT](#class_io_t) device

#### `{slot} public void `[`addEntry`](#class_main_content_1ad017995228905192aae4b87fed88fbf0)`(QString device)` {#class_main_content_1ad017995228905192aae4b87fed88fbf0}

addEntry

adds an entry to the model 
#### Parameters
* `device`

#### `{slot} public void `[`editEntry`](#class_main_content_1adaa870ab815c28f296261cec43080cbb)`(QString device)` {#class_main_content_1adaa870ab815c28f296261cec43080cbb}

editEntry

edit an entry in the model 
#### Parameters
* `device`

#### `{slot} public void `[`removeEntry`](#class_main_content_1a642b899032127df2deeba5743e45b9b5)`()` {#class_main_content_1a642b899032127df2deeba5743e45b9b5}

removeEntry

delete the entry from the model

#### `{slot} public void `[`editSelectedRow`](#class_main_content_1aa5de41aec3cac3585e37d137a1099640)`()` {#class_main_content_1aa5de41aec3cac3585e37d137a1099640}

editSelectedRow

call the showEditOrAddEntryDialog with the selected row

# class `MainWindow` {#class_main_window}

```
class MainWindow
  : public QMainWindow
```  

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`MainWindow`](#class_main_window_1a34c4b4207b46d11a4100c9b19f0e81bb)`()` | 
`protected void `[`contextMenuEvent`](#class_main_window_1a9fdfec5708365ddc98b17e431398841f)`(QContextMenuEvent * event)` | 

## Members

#### `public  `[`MainWindow`](#class_main_window_1a34c4b4207b46d11a4100c9b19f0e81bb)`()` {#class_main_window_1a34c4b4207b46d11a4100c9b19f0e81bb}

#### `protected void `[`contextMenuEvent`](#class_main_window_1a9fdfec5708365ddc98b17e431398841f)`(QContextMenuEvent * event)` {#class_main_window_1a9fdfec5708365ddc98b17e431398841f}

# class `Model` {#class_model}

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`Model`](#class_model_1a1feeb08aa4c59dd22c1399ae11a8b039)`(const std::string & filePath)` | [Model](#class_model).
`public bool `[`load`](#class_model_1a0c0a64c2044ede0a0e5be4aa5259a80d)`(const std::string & filePath)` | load
`public bool `[`save`](#class_model_1ac6fc1cf1217c93b46ffca9a467deb6bc)`(const std::string & filePath) const` | save
`public bool `[`addDevice`](#class_model_1a9d3771dbbea36d54ffe3c26e54888584)`(const std::string & json_device)` | addDevice
`public bool `[`removeDevice`](#class_model_1a0db511ccec9971d91b7667446399b695)`(const std::string & json_device)` | removeDevice
`public bool `[`setDeviceStatus`](#class_model_1ac734a429739fddf715dfeec36857b21e)`(const std::string & status)` | setDeviceStatus
`public bool `[`setDeviceStatus`](#class_model_1ab9b69a559b3f9ab234cca3a83a81b45c)`(const std::string & status,int index)` | setDeviceStatus
`public const std::string `[`getSerializzation`](#class_model_1a73d659f37fe35ca5ecd0e9859e4d28e5)`() const` | getSerializzation
`public const std::string `[`getDeviceStatus`](#class_model_1acf7a3e860d705461fbfe2ec38d6a71db)`(const int index) const` | getDeviceStatus
`public const std::string `[`getDeviceFiltered`](#class_model_1a16646ca3389756f7a04e2cbc8025792d)`(const std::string values) const` | getDeviceFiltered
`public const std::string `[`getAllDevicesClass`](#class_model_1a3cb99fbd6bb21c8fd7925556795f7eab)`() const` | getAllDevicesClass
`public const std::string `[`getAllRooms`](#class_model_1a0e5990e765bc24ee008022c0f19b31c7)`() const` | getAllRooms
`public void `[`delRoom`](#class_model_1a70b2e8fd4106a0fb56522eabc6873f8e)`(const std::string & room)` | delRoom
`public int `[`size`](#class_model_1ae4b31e1405f6bd8a459cf163db2c8106)`() const` | size
`public `[`IoT`](#class_io_t)` * `[`getElementAt`](#class_model_1a6bebf7bc5d04d9b304a386d43405ea48)`(int index) const` | getElementAt
`public  `[`~Model`](#class_model_1ad6ebd2062a0b823db841a0b88baac4c0)`()` | 
`protected `[`IoTContainer`](#class_model_1_1_io_t_container)` `[`iotdev`](#class_model_1a7814b4eea7917167b64e9b10a8f57c03) | 
`protected void `[`fillDeviceContainer`](#class_model_1ace1d0433a98daf12cdfad6b5377cf146)`()` | 

## Members

#### `public  `[`Model`](#class_model_1a1feeb08aa4c59dd22c1399ae11a8b039)`(const std::string & filePath)` {#class_model_1a1feeb08aa4c59dd22c1399ae11a8b039}

[Model](#class_model).

#### Parameters
* `filePath`

#### `public bool `[`load`](#class_model_1a0c0a64c2044ede0a0e5be4aa5259a80d)`(const std::string & filePath)` {#class_model_1a0c0a64c2044ede0a0e5be4aa5259a80d}

load

#### Parameters
* `filePath` 

#### Returns

#### `public bool `[`save`](#class_model_1ac6fc1cf1217c93b46ffca9a467deb6bc)`(const std::string & filePath) const` {#class_model_1ac6fc1cf1217c93b46ffca9a467deb6bc}

save

#### Parameters
* `filePath` 

#### Returns

#### `public bool `[`addDevice`](#class_model_1a9d3771dbbea36d54ffe3c26e54888584)`(const std::string & json_device)` {#class_model_1a9d3771dbbea36d54ffe3c26e54888584}

addDevice

#### Parameters
* `json_device` 

#### Returns

#### `public bool `[`removeDevice`](#class_model_1a0db511ccec9971d91b7667446399b695)`(const std::string & json_device)` {#class_model_1a0db511ccec9971d91b7667446399b695}

removeDevice

does perfom a deep delete of the element 
#### Parameters
* `json_device` 

#### Returns

#### `public bool `[`setDeviceStatus`](#class_model_1ac734a429739fddf715dfeec36857b21e)`(const std::string & status)` {#class_model_1ac734a429739fddf715dfeec36857b21e}

setDeviceStatus

#### Parameters
* `status` 

#### Returns

#### `public bool `[`setDeviceStatus`](#class_model_1ab9b69a559b3f9ab234cca3a83a81b45c)`(const std::string & status,int index)` {#class_model_1ab9b69a559b3f9ab234cca3a83a81b45c}

setDeviceStatus

#### Parameters
* `status` 

* `index` 

#### Returns

#### `public const std::string `[`getSerializzation`](#class_model_1a73d659f37fe35ca5ecd0e9859e4d28e5)`() const` {#class_model_1a73d659f37fe35ca5ecd0e9859e4d28e5}

getSerializzation

#### Returns

#### `public const std::string `[`getDeviceStatus`](#class_model_1acf7a3e860d705461fbfe2ec38d6a71db)`(const int index) const` {#class_model_1acf7a3e860d705461fbfe2ec38d6a71db}

getDeviceStatus

#### Parameters
* `index` 

#### Returns

#### `public const std::string `[`getDeviceFiltered`](#class_model_1a16646ca3389756f7a04e2cbc8025792d)`(const std::string values) const` {#class_model_1a16646ca3389756f7a04e2cbc8025792d}

getDeviceFiltered

#### Parameters
* `values` 

#### Returns

#### `public const std::string `[`getAllDevicesClass`](#class_model_1a3cb99fbd6bb21c8fd7925556795f7eab)`() const` {#class_model_1a3cb99fbd6bb21c8fd7925556795f7eab}

getAllDevicesClass

#### Returns

#### `public const std::string `[`getAllRooms`](#class_model_1a0e5990e765bc24ee008022c0f19b31c7)`() const` {#class_model_1a0e5990e765bc24ee008022c0f19b31c7}

getAllRooms

#### Returns

#### `public void `[`delRoom`](#class_model_1a70b2e8fd4106a0fb56522eabc6873f8e)`(const std::string & room)` {#class_model_1a70b2e8fd4106a0fb56522eabc6873f8e}

delRoom

#### Parameters
* `room`

#### `public int `[`size`](#class_model_1ae4b31e1405f6bd8a459cf163db2c8106)`() const` {#class_model_1ae4b31e1405f6bd8a459cf163db2c8106}

size

#### Returns

#### `public `[`IoT`](#class_io_t)` * `[`getElementAt`](#class_model_1a6bebf7bc5d04d9b304a386d43405ea48)`(int index) const` {#class_model_1a6bebf7bc5d04d9b304a386d43405ea48}

getElementAt

#### Parameters
* `index` 

#### Returns

#### `public  `[`~Model`](#class_model_1ad6ebd2062a0b823db841a0b88baac4c0)`()` {#class_model_1ad6ebd2062a0b823db841a0b88baac4c0}

#### `protected `[`IoTContainer`](#class_model_1_1_io_t_container)` `[`iotdev`](#class_model_1a7814b4eea7917167b64e9b10a8f57c03) {#class_model_1a7814b4eea7917167b64e9b10a8f57c03}

#### `protected void `[`fillDeviceContainer`](#class_model_1ace1d0433a98daf12cdfad6b5377cf146)`()` {#class_model_1ace1d0433a98daf12cdfad6b5377cf146}

# class `Container::Node` {#class_container_1_1_node}

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public const bool `[`first`](#class_container_1_1_node_1ae2fce0568220f679899fea17df9ac829) | 
`public T `[`data`](#class_container_1_1_node_1a2efcd41066c59f6a8e6e2effd0de0d14) | 
`public Node * `[`previous`](#class_container_1_1_node_1a34065f289906cbb83060939831921d72) | 
`public Node * `[`next`](#class_container_1_1_node_1a49e123f7bd15b8b38f7958037864adfe) | 
`public inline  `[`Node`](#class_container_1_1_node_1ad0eaa949309c0fdd2a439629de730159)`(const T & fData,Node * fPrevious,Node * fNext)` | Node.
`public inline  `[`Node`](#class_container_1_1_node_1a82121b7ddd7f9799362884d801a6a38b)`(const Node & c)` | Node.
`public inline  `[`Node`](#class_container_1_1_node_1ae700bce8185b0d2663648cf1409e3e01)`()` | Node.
`public inline  `[`~Node`](#class_container_1_1_node_1ac9c1999dc81608fb0bb73b778fd0d66a)`()` | 

## Members

#### `public const bool `[`first`](#class_container_1_1_node_1ae2fce0568220f679899fea17df9ac829) {#class_container_1_1_node_1ae2fce0568220f679899fea17df9ac829}

#### `public T `[`data`](#class_container_1_1_node_1a2efcd41066c59f6a8e6e2effd0de0d14) {#class_container_1_1_node_1a2efcd41066c59f6a8e6e2effd0de0d14}

#### `public Node * `[`previous`](#class_container_1_1_node_1a34065f289906cbb83060939831921d72) {#class_container_1_1_node_1a34065f289906cbb83060939831921d72}

#### `public Node * `[`next`](#class_container_1_1_node_1a49e123f7bd15b8b38f7958037864adfe) {#class_container_1_1_node_1a49e123f7bd15b8b38f7958037864adfe}

#### `public inline  `[`Node`](#class_container_1_1_node_1ad0eaa949309c0fdd2a439629de730159)`(const T & fData,Node * fPrevious,Node * fNext)` {#class_container_1_1_node_1ad0eaa949309c0fdd2a439629de730159}

Node.

Complete constructor 
#### Parameters
* `fData` 

* `fPrevious` 

* `fNext`

#### `public inline  `[`Node`](#class_container_1_1_node_1a82121b7ddd7f9799362884d801a6a38b)`(const Node & c)` {#class_container_1_1_node_1a82121b7ddd7f9799362884d801a6a38b}

Node.

Copy constructor

#### Parameters
* `c`

#### `public inline  `[`Node`](#class_container_1_1_node_1ae700bce8185b0d2663648cf1409e3e01)`()` {#class_container_1_1_node_1ae700bce8185b0d2663648cf1409e3e01}

Node.

Default constructor should be used only as first node

#### `public inline  `[`~Node`](#class_container_1_1_node_1ac9c1999dc81608fb0bb73b778fd0d66a)`()` {#class_container_1_1_node_1ac9c1999dc81608fb0bb73b778fd0d66a}

# class `Shutter` {#class_shutter}

```
class Shutter
  : public IoT
  : public IoT
```  

specific [IoT](#class_io_t) implementation for [Shutter](#class_shutter) devices

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`Shutter`](#class_shutter_1aaea3eea6b0853931af9333b989cf29c4)`(const std::string & fSerial,const std::string & fRoom,const std::string & fName)` | [Shutter](#class_shutter).
`public  `[`Shutter`](#class_shutter_1af79a29e857cbd9cd58846dd58ec238b8)`(const QJsonDocument & initializer)` | [Shutter](#class_shutter).
`public virtual const QJsonDocument & `[`getDeviceInstruction`](#class_shutter_1aa3d364d50cdfd42929239f63e44295f3)`() const` | getDeviceInstruction
`public virtual void `[`setDevice`](#class_shutter_1a8514c7b98d4b1a51fc0308bcf5cdc58b)`(const QJsonDocument & instruction)` | setDevice
`public virtual `[`IoT`](#class_io_t)` * `[`clone`](#class_shutter_1aa0e7e9e72deb935e309e6e5d460d2369)`() const` | clone

## Members

#### `public  `[`Shutter`](#class_shutter_1aaea3eea6b0853931af9333b989cf29c4)`(const std::string & fSerial,const std::string & fRoom,const std::string & fName)` {#class_shutter_1aaea3eea6b0853931af9333b989cf29c4}

[Shutter](#class_shutter).

Base constructor only serial is needed recalls [IoT](#class_io_t) base constructor with fClass = lClass

#### Parameters
* `fSerial` 

* `fRoom` 

* `fName`

#### `public  `[`Shutter`](#class_shutter_1af79a29e857cbd9cd58846dd58ec238b8)`(const QJsonDocument & initializer)` {#class_shutter_1af79a29e857cbd9cd58846dd58ec238b8}

[Shutter](#class_shutter).

Works like the other constructor saving all the data inside a QJsonDocument recalls [IoT](#class_io_t) base constructor with fClass = lClass

#### Parameters
* `initializer`

#### `public virtual const QJsonDocument & `[`getDeviceInstruction`](#class_shutter_1aa3d364d50cdfd42929239f63e44295f3)`() const` {#class_shutter_1aa3d364d50cdfd42929239f63e44295f3}

getDeviceInstruction

specific [Shutter](#class_shutter) implementation of the virtual method IoT::instruction depends on the type of the [IoT](#class_io_t) device

#### Returns
const QJsonDocument& that contains the device instruction

#### `public virtual void `[`setDevice`](#class_shutter_1a8514c7b98d4b1a51fc0308bcf5cdc58b)`(const QJsonDocument & instruction)` {#class_shutter_1a8514c7b98d4b1a51fc0308bcf5cdc58b}

setDevice

specific [Shutter](#class_shutter) implementation of the virtual method [IoT::setDevice()](#class_io_t_1ad5a9af49c5d4674ac845a36fba07ea30) depends on the type of the [IoT](#class_io_t) device

#### Parameters
* `instruction`

#### `public virtual `[`IoT`](#class_io_t)` * `[`clone`](#class_shutter_1aa0e7e9e72deb935e309e6e5d460d2369)`() const` {#class_shutter_1aa0e7e9e72deb935e309e6e5d460d2369}

clone

specific [Shutter](#class_shutter) implementation of the virtual method [IoT::clone()](#class_io_t_1a8e2dd15b9eb0341576fdd3450649b8c5) depends on the type of the [IoT](#class_io_t) device

#### Returns
[IoT](#class_io_t) pointer with the cloned object

# class `Switch` {#class_switch}

```
class Switch
  : public IoT
  : public IoT
```  

specific [IoT](#class_io_t) implementation for [Switch](#class_switch) devices

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public  `[`Switch`](#class_switch_1a0ad162f552129e25a75a0b800b8b7c4c)`(const std::string & fSerial,const std::string & fRoom,const std::string & fName)` | [Switch](#class_switch).
`public  `[`Switch`](#class_switch_1a10d28c7b2511ea80088e4f78102cd4de)`(const QJsonDocument & initializer)` | [Switch](#class_switch).
`public virtual const QJsonDocument & `[`getDeviceInstruction`](#class_switch_1a76495922ffbb474abd143d1ee71b0369)`() const` | getDeviceInstruction
`public virtual `[`IoT`](#class_io_t)` * `[`clone`](#class_switch_1a2fc3e44f785f55baa8e7a2e8d20047da)`() const` | clone
`public virtual void `[`setDevice`](#class_switch_1af3a2c68003019f7b9b3f459926925a92)`(const QJsonDocument & instruction)` | setDevice

## Members

#### `public  `[`Switch`](#class_switch_1a0ad162f552129e25a75a0b800b8b7c4c)`(const std::string & fSerial,const std::string & fRoom,const std::string & fName)` {#class_switch_1a0ad162f552129e25a75a0b800b8b7c4c}

[Switch](#class_switch).

Base constructor only serial is needed recalls [IoT](#class_io_t) base constructor with fClass = lClass

#### Parameters
* `fSerial` 

* `fRoom` 

* `fName`

#### `public  `[`Switch`](#class_switch_1a10d28c7b2511ea80088e4f78102cd4de)`(const QJsonDocument & initializer)` {#class_switch_1a10d28c7b2511ea80088e4f78102cd4de}

[Switch](#class_switch).

Works like the other constructor saving all the data inside a QJsonDocument recalls [IoT](#class_io_t) base constructor with fClass = lClass

#### Parameters
* `initializer`

#### `public virtual const QJsonDocument & `[`getDeviceInstruction`](#class_switch_1a76495922ffbb474abd143d1ee71b0369)`() const` {#class_switch_1a76495922ffbb474abd143d1ee71b0369}

getDeviceInstruction

specific switch implementation of the virtual method IoT::instruction depends on the type of the [IoT](#class_io_t) device

#### Returns
const QJsonDocument& that contains the device instruction

#### `public virtual `[`IoT`](#class_io_t)` * `[`clone`](#class_switch_1a2fc3e44f785f55baa8e7a2e8d20047da)`() const` {#class_switch_1a2fc3e44f785f55baa8e7a2e8d20047da}

clone

specific switch implementation of the virtual method [IoT::clone()](#class_io_t_1a8e2dd15b9eb0341576fdd3450649b8c5) depends on the type of the [IoT](#class_io_t) device

#### Returns
[IoT](#class_io_t) pointer with the cloned object

#### `public virtual void `[`setDevice`](#class_switch_1af3a2c68003019f7b9b3f459926925a92)`(const QJsonDocument & instruction)` {#class_switch_1af3a2c68003019f7b9b3f459926925a92}

setDevice

specific switch implementation of the virtual method [IoT::setDevice()](#class_io_t_1ad5a9af49c5d4674ac845a36fba07ea30) depends on the type of the [IoT](#class_io_t) device

#### Parameters
* `instruction`

Generated by [Moxygen](https://sourcey.com/moxygen)