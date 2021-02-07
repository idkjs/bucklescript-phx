open Phx_abstract
type t = {
  @bs.get
  "protocol": /* constructor(endPoint: string, opts?: Object); */
  /* defined as function */
  /* protocol(): string; */
  string,
  @bs.get
  "endPointURL": /* endPointURL(): string; */
  string,
  @bs.meth
  "log": /* disconnect(callback?: Function, code?: string, reason?: any): void; */
  /* defined as function since bs doesn't allow method to be curried */
  /* connect(params?: any): void; */
  /* defined as function since bs doesn't allow method to be curried */
  /* log(kind: string, msg: string, data: any): void; */
  (string, string, any) => void,
  @bs.meth
  "onOpen": /* onOpen(callback: Function): void; */
  function_ => void,
  @bs.meth
  "onClose": /* onClose(callback: Function): void; */
  function_ => void,
  @bs.meth
  "onError": /* onError(callback: Function): void; */
  function_ => void,
  @bs.meth
  "onMessage": /* onMessage(callback: Function): void; */
  function_ => void,
  @bs.get
  "onConnOpen": /* onConnOpen(): void; */
  void,
  @bs.meth
  "onConnClose": /* onConnClose(event: any): void; */
  any => void,
  @bs.meth
  "onConnError": /* onConnError(error: any): void; */
  any => void,
  @bs.get
  "triggerChanError": /* triggerChanError(): void; */
  void,
  @bs.get
  "connectionState": /* connectionState(): string; */
  string,
  @bs.get
  "isConnected": /* isConnected(): boolean; */
  bool,
  @bs.meth
  "remove": /* remove(channel: Channel): void; */
  Phx_channel.t => void,
  @bs.meth
  "push": /* channel(topic: string, chanParams?: Object): Channel; */
  /* defined as function since bs doesn't allow method to be curried */
  /* push(data: any): void; */
  any => void,
  @bs.get
  "makeRef": /* makeRef(): string; */
  string,
  @bs.get
  "sendHeartbeat": /* sendHeartbeat(): void; */
  void,
  @bs.get
  "flushSendBuffer": /* flushSendBuffer(): void; */
  void,
  @bs.meth
  "onConnMessage": /* onConnMessage(rawMessage: any): void; */
  any => void,
}

/* constructor(endPoint: string, opts?: Object); */
@bs.new @bs.module("phoenix")
external init: (string, ~opts: Js.t<'opts>=?, unit) => t = "Socket"
let init = (~opts: option<Js.t<'opts>>=?, path) => init(path, ~opts?, ())

/* Chris McCord: "The Channel's consturctor is private. You should only create channel instances off the socket's channel/2 function." */
/* constructor(topic: string, params?: Object, socket?: Socket); */
@bs.new @bs.module("phoenix")
external initChannel: (string, ~params: Js.t<'params>=?, ~socket: t=?, unit) => Phx_channel.t =
  "Channel"
let initChannel = (~params=?, ~socket=?, topic) => initChannel(topic, ~params?, ~socket?, ())

/* channel(topic: string, chanParams?: Object): Channel; */
@bs.send
external channel: (t, string, ~chanParams: Js.t<'chanParams>=?, unit) => Phx_channel.t = "channel"
let channel = (topic, ~chanParams=?, socket) => channel(socket, topic, ~chanParams?, ())

/* disconnect(callback?: Function, code?: string, reason?: any): void; */
@bs.send
external disconnect: (
  t,
  ~callback: function_=?,
  ~code: string=?,
  ~reason: Js.t<'reason>=?,
  unit,
) => void = "disconnect"
let disconnect = (
  ~callback: option<function_>=?,
  ~code: option<string>=?,
  ~reason: option<Js.t<'reason>>=?,
  socket,
) => {
  let _ = disconnect(~callback?, ~code?, ~reason?, socket, ())
  socket
}

/* connect(params?: any): void; */
@bs.send
external connect: (t, ~params: Js.t<'params>=?, unit) => void = "connect"
let connect = (~params: option<Js.t<'params>>=?, socket) => {
  let _ = connect(~params?, socket, ())
  socket
}
