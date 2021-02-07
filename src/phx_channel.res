open Phx_abstract
type t = {
  @bs.get
  "rejoinUntilConnected": /* constructor(topic: string, params?: Object, socket?: Socket); */
  /* defined as function in Phx_socket duo to circle dependency */
  /* rejoinUntilConnected(): void; */
  void,
  @bs.meth
  "onClose": /* join(timeout?: number): Push; */
  /* defined as function since bs doesn't allow method to be curried */
  /* leave(timeout?: number): Push; */
  /* defined as function since bs doesn't allow method to be curried */
  /* onClose(callback: Function): void; */
  function_ => void,
  @bs.meth
  "onError": /* onError(callback: (reason?: any) => void): void; */
  (any => void) => void,
  @bs.meth
  "onMessage": /* onMessage(event: string, payload: any, ref: any): any; */
  (string, any, any) => any,
  @bs.meth
  "on": /* on(event: string, callback: (response?: any) => void): void; */
  (string, any => void) => void,
  @bs.meth
  "off": /* off(event: string): void; */
  string => void,
  @bs.get
  "canPush": /* canPush(): boolean; */
  bool,
  /* push(event: string, payload: Object, timeout?: number): Push; */
  /* defined as function since bs doesn't allow method to be curried */
}

/* join(timeout?: number): Push; */
@bs.send external join: (t, ~timeout: float=?, unit) => Phx_push.t = "join"
let join = (~timeout: option<float>=?, channel) => join(channel, ~timeout?, ())

/* leave(timeout?: number): Push; */
@bs.send
external leave: (t, ~timeout: float=?, unit) => Phx_push.t = "leave"
let leave = (~timeout: option<float>=?, channel) => leave(channel, ~timeout?, ())

/* constructor(channel: Channel, event: string, payload: any, timeout: number); */
@bs.new @bs.module("phoenix")
external initPush: (t, string, Js.t<'payload>, float) => Phx_push.t = "Push"
let initPush = (event, payload, timeout, channel) => initPush(channel, event, payload, timeout)

/* push(event: string, payload: Object, timeout?: number): Push; */
@bs.send
external push: (t, string, Js.t<'payload>, ~timeout: float=?, unit) => Phx_push.t = "push"
let push = (event, payload, ~timeout=?, channel) => push(channel, event, payload, ~timeout?, ())
