open Phx_abstract;
type t = {
  .
  /*constructor(topic: string, params?: Object, socket?: Socket);*/
  /*defined as function in Phx_socket duo to circle dependency*/
  /*rejoinUntilConnected(): void;*/
  [@bs.get] "rejoinUntilConnected": void,
  /*join(timeout?: number): Push;*/
  /*defined as function since bs doesn't allow method to be curried*/
  /*leave(timeout?: number): Push;*/
  /*defined as function since bs doesn't allow method to be curried*/
  /*onClose(callback: Function): void;*/
  [@bs.meth] "onClose": function_ => void,
  /*onError(callback: (reason?: any) => void): void;*/
  [@bs.meth] "onError": (any => void) => void,
  /*onMessage(event: string, payload: any, ref: any): any;*/
  [@bs.meth] "onMessage": (string, any, any) => any,
  /*on(event: string, callback: (response?: any) => void): void;*/
  [@bs.meth] "on": (string, any => void) => void,
  /*off(event: string): void;*/
  [@bs.meth] "off": string => void,
  /*canPush(): boolean;*/
  [@bs.get] "canPush": bool,
  /*push(event: string, payload: Object, timeout?: number): Push;*/
  /*defined as function since bs doesn't allow method to be curried*/
};

/*join(timeout?: number): Push;*/
[@bs.send] external join: (t, ~timeout: float=?, unit) => Phx_push.t = "join";
let join = (~timeout: option(float)=?, channel) =>
  join(channel, ~timeout?, ());

/*leave(timeout?: number): Push;*/
[@bs.send]
external leave: (t, ~timeout: float=?, unit) => Phx_push.t = "leave";
let leave = (~timeout: option(float)=?, channel) =>
  leave(channel, ~timeout?, ());

/*constructor(channel: Channel, event: string, payload: any, timeout: number);*/
[@bs.new] [@bs.module "phoenix"]
external initPush: (t, string, Js.t('payload), float) => Phx_push.t = "Push";
let initPush = (event, payload, timeout, channel) =>
  initPush(channel, event, payload, timeout);

/*push(event: string, payload: Object, timeout?: number): Push;*/
[@bs.send]
external push:
  (t, string, Js.t('payload), ~timeout: float=?, unit) => Phx_push.t =
  "push";
let push = (event, payload, ~timeout=?, channel) =>
  push(channel, event, payload, ~timeout?, ());
